// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int main() 
{ 
  string s1,s2;
  cin>>s1>>s2;
  int cnt=0;
  if (s1.size() != s2.size())
     cout<<"Not an anagram"<<endl;
  else{
    for(int i=0;i<s1.size();i++){
      cnt+=(int)s1[i];
    }
    for(int i=0;i<s2.size();i++){
      cnt-=(int)s2[i];
    }
    if(cnt!=0){
      cout<<"Not an anagram"<<endl;
    }else{
      cout<<"Its an anagram!"<<endl;
    }

  }
  return 0; 
} 
