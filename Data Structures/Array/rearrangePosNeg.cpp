#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9}; 
  int n = sizeof(a) / sizeof(a[0]);
  int i = -1;
  for(int j=0;j<n;j++){
    if(a[j]<0){
      i++;
      swap(a[i], a[j]);
    }
  }
  int pos = i+1, neg = 0;
  while(pos<n && neg<pos && a[neg]<0){
    swap(a[pos], a[neg]);
    pos++;
    neg += 2;
  }

  for(int k=0;k<n;k++) cout<<a[k]<<" ";
}