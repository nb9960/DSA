#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {1,2,-1,7,5};
  int n = sizeof(a)/sizeof(a[0]);
  int min_num = a[0], second = INT_MIN,third = INT_MIN;
  int length = 1, store_min = min_num; //track best sequence length
  for(int i=1;i<n;i++){
    if(a[i] == min_num){
      continue;
    }else if(a[i]<min_num){
      min_num = a[i];
      continue;
    }else if(a[i] < second){
      second = a[i];
      store_min = min_num;
    }else if(a[i]>second){
      length ++;
      if(length == 3){
        cout<<store_min<<" "<<second<<" "<<a[i]<<endl;
        return 0;
      }
      second = a[i];
    }
  } 
  cout<<"No triplet found"<<endl;
  return 0;
}