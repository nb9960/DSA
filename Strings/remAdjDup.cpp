// Recursively remove all adjacent duplicates

// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

string remove(string s,char ch){
  if(s.empty() || s.length()<=1)
    return s;
  int i=0;
  while(i<s.length()){
    if(i+1<s.length() && s[i]==s[i+1]){
      int j=i;
      while(j+1<s.length() && s[j]==s[j+1])
        j++;
      char lastChar = i>0 ? s[i-1] : ch;
      string rem = remove(s.substr(j+1,s.length()),lastChar);
      s=s.substr(0,i);
      int k=s.length(), l=0;
      // Recursively remove all the adjacent characters formed by removing adj characters
      while(rem.length()>0 && s.length()>0 && rem[0]==s[s.length()-1]){
        // Have to check whether this is the repeated char that matches the last char of the parent string
        while(rem.length()>0 && rem[0]!=ch && rem[0]==s[s.length()-1]){
          rem=rem.substr(1,rem.length());
        }
        s=s.substr(0,s.length()-1);
      }
      s += rem;
      i=j;
    }
    else i++;
  }
  return s;
}

int main() 
{  
  string s;
  cin>>s;
  cout<<remove(s,' ');
  return 0; 
} 
