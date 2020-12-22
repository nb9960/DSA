// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int main() 
{  
  int n;
  cin>>n;
  int f[n+2];
  f[0]=0; f[1]=1;
  fi(i,2,n+1){
    f[i]=f[i-1]+f[i-2];
  }
  cout<<f[n]<<endl;
  return 0; 
} 
