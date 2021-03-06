#include <bits/stdc++.h>
using namespace std;

int minJumps(int a[], int n){
  vector<int> jumps(n);
  jumps[n-1] = 0;
  for(int i=n-2;i>=0;i--){
    if(a[i] == 0) jumps[i] = INT_MAX;
    else if(a[i]>=n-i-1) jumps[i] = 1;
    else{
      int minm = INT_MAX;
      for(int j=i+1;j<n && j<= i+a[i];j++){
        if(minm>jumps[j]) minm=jumps[j];
      }
      minm != INT_MAX ? jumps[i] = minm+1 : jumps[i] = minm;
    }
  }
  return jumps[0];
}

int main(){
  int arr[] = {1,3,6,1,0,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<< minJumps(arr, n)<< endl;
  return 0;
}