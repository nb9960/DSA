#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {2,3,4,1,4,5};
  int n = sizeof(a)/sizeof(a[0]);
  int ans = -1;
  int i=0, start=0, end=n-1, left_sum=0, right_sum=0;
  for(i=0;i<n;i++){
    if(start==end && right_sum == left_sum){
      ans = a[start];
      break;
    }
    if(start == end) break;
    if(left_sum>right_sum){
      right_sum += a[end--];
    }else if(right_sum>left_sum){
      left_sum += a[start++];
    }else{
      //left_sum == right_sum
      right_sum += a[end--];
    }
  }
  if(!i){
    ans = a[0];
  }
  cout<<ans<<endl;
  return 0;
}