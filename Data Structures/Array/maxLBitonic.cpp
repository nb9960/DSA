#include <bits/stdc++.h>
using namespace std;

// bitonic == pehle increasing fir decreasing
// ek index ke corresponding length of increasiing subarray ending at that element
// aur length of decreasing subarray starting at that index store kr lo
// ans =maximum value of(inc[i] + dec[i] -1)

int main(){
  int a[] = {12,4,78,90,45,23};
  int n = sizeof(a)/sizeof(a[0]);

  int inc[n], dec[n];
  inc[0] = 1; dec[n-1] = 1;
  for(int i=1;i<n;i++)
    inc[i] = (a[i]>=a[i-1]) ? inc[i-1] + 1 : 1;
  for(int i=n-2;i>=0;i--)
    dec[i] = (a[i]>=a[i+1]) ? dec[i+1] + 1 : 1;

  int res = inc[0] + dec[0] -1;
  for(int i=1;i<n;i++)
    res = max(res, inc[i] + dec[i]-1);
  cout<<res<<endl;
  return 0;
}