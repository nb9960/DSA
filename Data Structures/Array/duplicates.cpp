#include <bits/stdc++.h>
using namespace std;

// VVIP method agar pata hai n-1 tak hi numbers hai array mei aur frequency check krni ho to
// final array m %array_size lene pe har index ki freq pata chal jaegi

int main(){
  int a[] = {0,4,3,2,7,8,2,3,1};
  int n = sizeof(a)/sizeof(a[0]);

  for(int i=0;i<n;i++){
    a[a[i]%n] += n;
  }
  for(int i=0;i<n;i++){
    if(a[i]>=n*2) cout<<i<<" ";
  }
  return 0;
}