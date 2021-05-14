#include <bits/stdc++.h>
using namespace std;

// JUGGLING ALGORITHM
int main(){
  int a[] = {1,2,3,4,5,6,7};
  int n=sizeof(a)/sizeof(a[0]);

  int d=2;
  d = d%n; // if d>=n
  int gcd = __gcd(d,n);
  for(int i=0;i<gcd;i++){
    int tmp = a[i];
    int j=i;
    while(1){
      int k = j+d;
      if(k>=n)
        k -= n;
      if(k == i)
        break;
      a[j] = a[k];
      j=k;
    }
    a[j] = tmp;
  }

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}