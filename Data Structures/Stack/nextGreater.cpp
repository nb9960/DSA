#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {11, 13, 21, 3};
  int n = sizeof(a)/sizeof(a[0]);
  stack<int> s;
  int res[n];
  for(int i=n-1;i>=0;i--){
    while(!s.empty() && s.top() <= a[i])
      s.pop();
    
    if(s.empty())
      res[i] = -1;
    else res[i] = s.top();
    s.push(a[i]);
  }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" --> "<<res[i]<<endl;
  return 0;
}