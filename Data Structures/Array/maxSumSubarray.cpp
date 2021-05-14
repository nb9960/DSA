#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {-2,-3,4,-1,-2,1,5,-1};
  int n = sizeof(a)/sizeof(a[0]);

  int max_so_far = a[0], curr_max = a[0];
  for(int i=1;i<n;i++){
    curr_max = max(a[i], curr_max + a[i]);
    max_so_far = max(curr_max, max_so_far);
  }
  cout<<max_so_far<<endl;

  return 0;
}