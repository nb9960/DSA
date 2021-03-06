#include <bits/stdc++.h>
using namespace std;
#define fi(i,a,n) for(int i = a; i<n;i++)

int knapSackRec(int W, int wt[], int val[], int i, int** dp){
  if(i<0) return 0;
  if(dp[i][W] != -1) return dp[i][W];
  if(wt[i]>W){
    dp[i][W] = knapSackRec(W, wt, val,i-1, dp);
    return dp[i][W];
  }else{
    dp[i][W] = max(val[i] + knapSackRec(W-wt[i], wt, val, i-1, dp), knapSackRec(W, wt, val, i-1, dp));
    return dp[i][W];
  }
}

int knapSack(int W, int wt[], int val[], int n){
  int **dp;
  dp = new int*[n];
  fi(i,0,n) dp[i] = new int[W+1];
  fi(i,0,n){
    fi(j,0,W+1)
      dp[i][j] = -1;
  }
  return knapSackRec(W,wt,val,n-1, dp);
}

int main(){
  int val[] = {60,100,120};
  int wt[] = {10,20,30};
  int W = 50;
  int n = sizeof(val)/sizeof(val[0]);
  cout<<knapSack(W,wt,val,n);
  return 0;
}