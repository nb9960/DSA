#include <bits/stdc++.h>
using namespace std;
#define fi(i,a,n) for(int i=a; i<n;i++)

void sortK(int a[], int n, int k){
  priority_queue<int, vector<int>, greater<int>> pq(a, a+k+1);
  int ind = 0;
  fi(i,k+1,n){
    a[ind++] = pq.top();
    pq.pop();
    pq.push(a[i]);
  }
  while(!pq.empty()){
    a[ind++] = pq.top();
    pq.pop();
  }
}

int main(){
  int k=3;
  int a[] = {2,6,3,12,56,8};
  int n = sizeof(a)/sizeof(a[0]);
  sortK(a,n,k);
  fi(i,0,n) cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}