#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int main(){
  ll n;
  cin>>n;
  ll dp[n+1];
  dp[0]=1;
  for(ll i=1;i<n+1;i++){
    dp[i]=0;
    for(ll j=1;j<=6;j++){
      if(i-j>=0)
        dp[i] += (dp[i-j]%MOD);
    }
  }
  cout<<dp[n]%MOD<<endl;
  return 0;
}