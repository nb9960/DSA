// an element is leader if all elements to its right are than that element
#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {16,17,4,3,5,2};
  int n = sizeof(n)/sizeof(a[0]);

  //scan from right and set max if max changes its value mtlb leader
  int maxm = a[n-1]; //n-1 hmesha hi leader j
  cout<<maxm<<" ";
  for(int i=n-2;i>=0;i--){
    if(a[i]>=maxm){
      maxm = a[i];
      cout<<maxm<<" ";
    }
  }
  return 0;
}