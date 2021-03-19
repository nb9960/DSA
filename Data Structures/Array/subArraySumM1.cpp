#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {10, 2, -2, -20, 10}; 
  int n = sizeof(a)/sizeof(a[0]); 
  int sum = -10;  
  int curr_sum=0;
  int start_ind = -1, end_ind = -1;
  unordered_map<int, int> mp;
  for(int i=0;i<n;i++){
    curr_sum += a[i];
    if(curr_sum == sum){
      start_ind = 0; end_ind = i;
      break;
    }
    if(mp.find(curr_sum - sum) != mp.end()){
      start_ind = mp[curr_sum - sum];
      end_ind = i;
      break;
    }
    mp[curr_sum] = i;
  }
  cout<<start_ind<<" "<<end_ind<<endl;
  return 0;
}