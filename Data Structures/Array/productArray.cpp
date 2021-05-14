#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[]={10,3,5,6,2};
  int n = sizeof(a)/sizeof(a[0]);
  int prod[n];
  for(int i=0;i<n;i++){
    prod[i]=1;
  }
  int tmp=1;
  for(int i=0;i<n;i++){
    prod[i] *= tmp;
    tmp *= a[i];
    // cout<<prod[i]<<endl;
  }
  tmp = 1;
  for(int i=n-1;i>=0;i--){
    prod[i] *= tmp;
    tmp *= a[i];
    // cout<<prod[i]<<endl;
  }
  for(int i=0;i<n;i++){
    cout<<prod[i]<<" ";
  }
  return 0;
}