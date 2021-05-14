#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi(i,a,n) for(ll i=a;i<=n;i++)

int main(){
  ll n,x;
  cin>>n>>x;
  ll coins[n];
  fi(i,0,n-1) cin>>coins[i];
  ll dp[x+1];
  dp[0]=0;
  fi(i,1,x) dp[i] = INT_MAX;
  fi(i,1,x){
    fi(j,0,n-1){
      if(coins[j]<=i){
        ll subRes = dp[i-coins[j]];
        if(subRes != INT_MAX && subRes + 1< dp[i]) dp[i] = subRes+1;
      }
    }
  }
  if(dp[x]==INT_MAX) dp[x]=-1;
  cout<<dp[x]<<endl;
  return 0;
}
