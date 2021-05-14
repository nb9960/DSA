#include <bits/stdc++.h>
using namespace std;
#define fi(i,a,n) for(int i=a;i<n;i++)

int main(){
  int n,x;
  cin>>n>>x;
  int price[n], pages[n];
  fi(i,0,n) cin>>price[i];
  fi(i,0,n) cin>>pages[i];
  // dp[i]=max no. of pages I can read if I have 
  // i amount of money
  int dp[x+1];
  return 0;
}