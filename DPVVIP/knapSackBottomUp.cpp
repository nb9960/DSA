#include <bits/stdc++.h>
using namespace std;
#define fi(i,a,n) for(int i=a;i<=n;i++)

int main(){
  int n, W;
  cin>>n>>W;
  int wt[n], val[n];
  fi(i,0,n-1) cin>>wt[i];
  fi(i,0,n-1) cin>>val[i];

  /*
  dp[i][j]= max value for "weight j" considering all "values" from 1 to i
  agar ith value nahi utha rahe toh dp[i][j]=dp[i-1][j]
  warna dp[i][j]=dp[i][j-w[i]]
  */
  int dp[n+1][W+1];

  fi(i,0,n){
    fi(w,0,W){
      if(i==0 || w==0) dp[i][w]=0;
      else if(wt[i-1]<=w){
        dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
      }
      else dp[i][w] = dp[i-1][w];
    }
  }

  cout<<dp[n][W]<<endl;
  return 0;
}