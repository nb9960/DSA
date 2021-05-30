#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "geeks";
  int n = s.size();
  // dp[i][j] --> min no. of insertions needed to convert s[i...j] to plaindrome
  int dp[n][n];
  memset(dp, 0, sizeof(dp));

  for(int gap=1; gap < n; gap++)
    for(int l=0, h=gap; h < n; l++, h++)
      dp[l][h] = (s[l] == s[h]) ? dp[l+1][h-1] : min(dp[l][h-1], dp[l+1][h]) +1;
 
  cout<<dp[0][n-1]<<endl;
  return 0;
}