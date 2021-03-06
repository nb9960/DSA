#include <bits/stdc++.h>
using namespace std;
#define fi(i,a,n) for(int i=a;i<n;i++)
const int row = 3;
const int col = 3;

int minCost(int cost[row][col]){
  fi(i,1,row) cost[i][0] += cost[i-1][0];
  fi(i,1,col) cost[0][i] += cost[0][i-1];
  fi(i,1,row){
    fi(j,1,col)
      cost[i][j] += min(cost[i-1][j], min(cost[i-1][j-1], cost[i][j-1]));
  }
  return cost[row-1][col-1];
}

int main(){
  int cost[row][col] = {{1, 2, 3}, {4, 8, 2}, {1, 5,3}};
  cout<< minCost(cost);
  return 0;
}