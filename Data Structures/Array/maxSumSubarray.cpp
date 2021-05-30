#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {-2,-3,4,-1,-2,1,5,-1};
  int n = sizeof(a)/sizeof(a[0]);

  int max_so_far = INT_MIN, curr_max = 0, start =0, end=0, s=0;
  for(int i=0;i<n;i++){
    curr_max += a[i];
    if(max_so_far < curr_max){
      max_so_far = curr_max;
      start = s; end = i;
    } 
    if(max_so_far < 0){
      curr_max = 0; 
      s = i+1;
    }
  }
  cout<<"Max contiguous sum is "<<max_so_far<<" with starting index "<<start<<" and ending index "<<end<<endl;

  return 0;
}