// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int longestUniqueSubstr(string s){
  int n=s.size(),res=0;
  vector<int> lastInd(256,-1);
  int i=0;
  fi(j,0,n){
    i=max(i,lastInd[s[j]]+1);
    res=max(res,j-i+1);
    lastInd[s[j]]=j;
  }
  return res;
}

int main() 
{  
  string s;
  cin>>s;
  cout<<"The length of longest non-repeating character substring is: "<<longestUniqueSubstr(s);
  return 0; 
} 
