#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {1,0,0,1,0,1,1};
  int n = sizeof(a)/sizeof(a[0]);

  unordered_map<int, int> mp;
  int sum = 0, max_len = 0, endInd = -1;
  for(int i=0;i<n;i++)
    a[i] = (a[i]==0) ? -1 : 1;
  for(int i=0;i<n;i++){
    sum += a[i];
    if(sum==0){
      max_len = i+1;
      endInd = i;
    }
    if(mp.find(sum) != mp.end()){
      if(max_len < i-mp[sum]){
        max_len = i-mp[sum];
        endInd = i;
      }
    }else mp[sum] = i;
  }
  for(int i=0;i<n;i++)
    a[i] = (a[i] == -1) ? 0 : 1;
  cout<<endInd - max_len + 1<<" to "<<endInd<<endl;
  return 0;
}