#include <bits/stdc++.h>
using namespace std;
/*
Max diff b/w 2 elements a[i] & a[j] such that a[i]<a[j] && i<j
*/

/* easy wala: 
  int max_diff = a[1] - a[0]; 
  int min_element = a[0]; 
  for(i,1,n){ 
    if (a[i] - min_element > max_diff)                              
    max_diff = a[i] - min_element; 
    if (a[i] < min_element) 
    min_element = a[i];                      
  } 
  return max_diff; 
*/

/* tough wala: time O(n) & space O(1)
  adjacent elements ka diff dekho
*/
int main(){
  int a[] = {80,2,6,3,100};
  int n = sizeof(a)/sizeof(a[0]);
  int diff = a[1]-a[0];
  int curr_sum = diff;
  int max_sum = curr_sum;

  for(int i=1;i<n-1;i++){
    diff = a[i+1] - a[i];
    if(curr_sum>0) curr_sum+=diff;
    else curr_sum = diff;
    max_sum = max(max_sum, curr_sum);
  }
  cout<<max_sum<<endl;
  return 0;
}