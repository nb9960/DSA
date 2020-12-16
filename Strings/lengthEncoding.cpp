// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

void printRLE(string s){
  int n = s.size();
  fi(i,0,n){
    int cnt=1;
    while(i<n-1 && s[i]==s[i+1]){
      cnt++;
      i++;
    }
    cout<<s[i]<<cnt;
  }
}

int main() 
{  
  string s;
  cin>>s;
  printRLE(s);
  return 0; 
} 
