#include <bits/stdc++.h>
using namespace std;

int main(){
  priority_queue<int, vector<int>, greater<int>> pq;
  int k=3;
  int a[] = {11,3,2,1,15,5,4,45,88,96,50,45};
  int n = sizeof(a)/sizeof(a[0]);
  for(int i=0;i<n;i++){
    pq.push(a[i]);
    if(pq.size()>k) pq.pop();
  }
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  return 0;
}