#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi(i,a,n) for(ll i=a;i<=n;i++)

int main(){
  ll n;
  cin>>n;
  ll dp[n+1];
  dp[0]=0, dp[1]=1;
  fi(i,2,n){
    ll largest = 0;
    ll j=i;
    while(j){ 
      ll r = j%10;
      largest = max(r, largest); 
      j /= 10; 
    } 
    dp[i] = 1+dp[i-largest];
  }
  cout<<dp[n]<<endl;
  return 0;
}
