#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {5,5,10,100,10,5};
  int n = sizeof(a)/sizeof(a[0]);

  int incl=a[0], excl=0, excl_new; 
  // inc == max sum including prev element  = excl + a[i]
  // excl == max sum excluding prev element =max (incl,excl)
  for(int i=1;i<n;i++){
    excl_new = max(incl, excl);
    incl = excl + a[i];
    excl = excl_new;
  }
  cout<<max(excl, incl)<<endl;
  return 0;
}