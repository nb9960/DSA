#include <bits/stdc++.h>
using namespace std;
#define R 5
#define C 4

int main(){
  int n = 5, m=4;
  int a[][C] = {{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16},
                {17,18,19,20}};
  
  vector<vector<int>> res(n+m-1);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      res[i+j].push_back(a[j][i]);
    }
  }

  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}