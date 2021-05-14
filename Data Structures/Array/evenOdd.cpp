#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> a = {12,34,45,9,8,90,3};
  int n = a.size();
 
  //METHOD - 1
  // int j=-1;
  // for(int i=0;i<n;i++){
  //   if(a[i]%2==0){
  //     j++;
  //     swap(a[i],a[j]);
  //   }
  // }

  // METHOD-2 (USING STL)
  stable_partition(a.begin(), a.end(), [] (auto v) { return v%2 == 0;});

  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  return 0;
}
