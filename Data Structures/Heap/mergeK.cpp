#include <bits/stdc++.h>
using namespace std;
#define n 4
// first ele value store krega, 2nd index of array, 3rd element ka ind array m
typedef pair<int, pair<int, int>> ppi;
/*
min heap banao saare k arrays ke first element heap m daalo
while(heap.size()>0){
  remove top element and print it
  aur jiss array wala array remove kiya ussi ka agla element heap m daalo
}
*/

void mergeKArrays (vector<vector<int>> a){
  priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
  for(int i=0;i<a.size();i++){
    pq.push({a[i][0],{i,0}});
  }
  while(!pq.empty()){
    ppi curr = pq.top();
    pq.pop();
    int i = curr.second.first; // array num
    int j = curr.second.second; //index in the array
    cout<<curr.first<<" ";
    if(j+1 < a[i].size()) pq.push({a[i][j+1], {i,j+1}});
  }
}

int main(){
  vector<vector<int>> a{{2,6,12},{1,9},{23,34,90,2000}};
  mergeKArrays(a);
  return 0;
}
