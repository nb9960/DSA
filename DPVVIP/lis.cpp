#include <bits/stdc++.h>
using namespace std;

int msis(int a[], int n){
  int msis[n];
  int ans = INT_MIN;
  for(int i=0;i<n;i++)
    msis[i] = a[i];
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[i]>a[j] && msis[i]<msis[j]+a[i]){
        msis[i] = msis[j] + a[i]; 
        ans = max(ans, msis[i]);
      }
    }
  }
  return ans;
}

int _lis(int a[], int n){
  int L[n] = {1};
  int ans = 1;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[i] > a[j]){
        L[i] = max(L[i], 1 + L[j]);
        ans = max(ans, L[i]);
      }
    }
  }
  return ans;
}

int main(){
  int n = 7;
  int a[] = {1,101,2,3,100,4,5};
  
  cout<<"Longest Increasing subsequence: "<<_lis(a, n)<<endl;
  cout<<"Maximum sum Increasing subsequence: "<<msis(a, n)<<endl;
  return 0;
}