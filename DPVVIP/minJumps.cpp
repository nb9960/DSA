#include <bits/stdc++.h>
using namespace std;

int bottomUp(int arr[], int n){
  int mem[100];
  mem[0] = 0;
  for(int i=1;i<n;i++){
    mem[i] = INT_MAX;
    for(int j=0;j<i;j++){
      if(arr[j] +j >= i && mem[j] != INT_MAX){
        mem[i] = min(mem[i], mem[j]+1);
        break;
      }
    }
  }
  return mem[n-1];
}

int mem[100];
int solveTopDown(int i, int arr[], int n){
  if(mem[i]>0) return mem[i];
  if(i>=n) return INT_MAX;
  if(i==n-1) return 0;

  int steps = arr[i];
  int minValue = INT_MAX;
  for(int j=1;j<=steps;j++)
    minValue = min(minValue, solveTopDown(i+j, arr, n));
  mem[i] = minValue +1;
  return mem[i];
}

int main(){
  int arr[] = {1,3,6,1,0,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<< solveTopDown(0, arr, n)<< endl;
  cout<<bottomUp(arr, n)<<endl;
  return 0;
}