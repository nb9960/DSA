#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {6, -3, -10,0,2};
  int n = sizeof(a)/sizeof(a[0]);

  int max_ending_here = 1; //can either be 1 or positive
  int min_ending_here =1; //can either be 1 or negative
  int max_so_far = 0, flag =0;
  for(int i=0;i<n;i++){
    if(a[i]>0){
      max_ending_here *= a[i];
      min_ending_here = min(min_ending_here*a[i],1);
      flag=1; 
    }else if(a[i]==0){
      // 0 hai to mtlb ye subarray nhi ayega kyuki output hmesha positive assume kiya h
      max_ending_here=1;
      min_ending_here = 1;
    }else{
      int tmp = max_ending_here;
      max_ending_here = max(max_ending_here*a[i],1);
      min_ending_here = tmp*a[i];
    }

    if(max_so_far < max_ending_here)
      max_so_far = max_ending_here;
  }
  if(flag==0 && max_so_far == 0)
    cout<<0<<endl;
  else cout<<max_so_far<<endl;
  return 0;
}