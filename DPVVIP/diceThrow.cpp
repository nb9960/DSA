#include <bits/stdc++.h>
using namespace std;

/*
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X. 
X is the summation of values on each face when all the dice are thrown.
*/

int main(){
  int m = 6, n = 3, x = 8;
  //row--> n (no. of dice), col--> x (req sum)
  int dp[n+1][x+1];
  memset(dp,0, sizeof(dp));

  for(int j=1;j<=m && j<=x;j++) dp[1][j] = 1;

  for(int i=2;i<=n;i++)
    for(int j=1;j<=x;j++)
      for(int k=1;k<=m && k<j;k++)
        dp[i][j] += dp[i-1][j-k];

  cout<<"No. of ways to get sum X: "<<dp[n][x]<<endl;
  return 0;
}