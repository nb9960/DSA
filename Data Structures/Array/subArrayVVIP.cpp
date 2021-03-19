#include <bits/stdc++.h>
using namespace std;

// find subarray of array(that contains -ves too) where sums = given sum in O(n) and constant space

int main(){
  int a[] = { 10, -12, 2, -2, -20, 10 };
  int n = sizeof(a) / sizeof(a[0]);

  int sum = -10, minEl = INT_MAX;
  for(int i=0;i<n;i++) minEl = min(minEl, a[i]);

  int curr_sum = a[0] + abs(minEl), start=0, i;
  for(int i=1;i<=n;i++){
    while(curr_sum - (i-start) * abs(minEl) > sum && start<i){
      curr_sum = curr_sum - a[start] - abs(minEl);
      start++;
    }
    if(curr_sum - (i- start) * abs(minEl) == sum){
      cout<<start<<" "<<i-1<<endl;
      return 0;
    }
    if(i<n)
      curr_sum = curr_sum + a[i] + abs(minEl);
  }
  cout<<-1<<endl;
  return 0;
}