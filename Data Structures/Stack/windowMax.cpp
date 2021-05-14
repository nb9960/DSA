#include <bits/stdc++.h>
using namespace std;

void find_max(queue<int> q){
  int max = 0;
  while (!q.empty()){
    if (q.front() > max)
      max = q.front();
    q.pop();
  }
  cout << max << " ";
  return;
}

int main(){
  int a[] = {1,2,3,1,4,5,2,3,6};
  int size = 9;
  int k = 3; //window size
  
  //-------USING QUEUE-------- 
  // queue<int> q;
  // for(int i=0;i<size;i++){
  //   if(i<k)
  //     q.push(a[i]);
  //   else{
  //     find_max(q);
  //     q.pop();
  //     q.push(a[i]);
  //   }
  // }
  // find_max(q);

  //------------USING MULTISET-----------
  // multiset<int> s;
  // for(int i=0;i<k;i++)
  //   s.insert(a[i]);
  // cout<<*(--s.end())<<" ";
  // int start = 0;
  // for(int i=k;i<size;i++){
  //   s.insert(a[i]);
  //   s.erase(s.find(a[start]));
  //   start++;
  //   cout<<*(--s.end())<<" ";
  // }

  //--------USING DEQUEUE----------//
  deque<int> Q(k);
  int i;
  for(i=0;i<k;++i){
    while(!Q.empty() && a[i] >= a[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for(; i<size ;++i){
    cout<<a[Q.front()]<<" ";
    while(!Q.empty() && Q.front() <= i-k)
      Q.pop_front();
    while(!Q.empty() && a[i]>=a[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  cout<<a[Q.front()];
  return 0;
}