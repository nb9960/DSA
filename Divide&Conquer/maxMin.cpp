#include <bits/stdc++.h>
using namespace std;

int calcMax(int a[], int ind, int l){
  if(ind>=l-2){
    return max(a[ind], a[ind+1]);
  }
  int maxm = calcMax(a, ind+1, l);
  return max(maxm, a[ind]);
}

int calcMin(int a[], int ind, int l){
  if(ind>=l-2){
    return min(a[ind], a[ind+1]);
  }
  int minm = calcMin(a, ind+1, l);
  return min(minm, a[ind]);
} 

int main(){
  int a[] = {120, 34, 54, 32, 58, 11, 90};
  int n = sizeof(a)/sizeof(a[0]);
  int max = calcMax(a, 0,n), min= calcMin(a, 0,n);
  cout<<"Maximum: "<<max<<"\n"<<"Minimum: "<<min<<endl;
  return 0;
}