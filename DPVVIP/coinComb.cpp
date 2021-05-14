#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi(i,a,n) for(ll i=a;i<n;i++)
#define MOD 1000000007

int main(){
  ll n,x;
  cin>>n>>x;
  ll coins[n];
  fi(i,0,n) cin>>coins[i];
  ll dp[x+1];
  memset(dp, 0, sizeof(dp));
  dp[0]=1;
  for(ll i=1;i<x+1;i++){
    for(ll j=0;j<n;j++){
      if(i-coins[j]>=0)
        dp[i] += (dp[i-coins[j]]%MOD);
    }
  }
  cout<<dp[x]%MOD<<endl;
  return 0;
}