#include <bits/stdc++.h>
using namespace std;
#define fi(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define ll long long int

int main(){
  int n;
  cin>>n;
  char a[n][n];
  fi(i,0,n){
    fi(j,0,n){
      cin>>a[i][j];
    }
  }
  if(a[0][0]=='*'){
    cout<<0<<endl;
  }else{
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    fi(i,0,n){
      if(a[i][0] != '*') dp[i][0] = 1;
      else {
        dp[i][0] = -1; 
        break;
      }
    }
    fi(i,1,n){
      if(a[0][i] != '*') dp[0][i] = 1;
      else {
        dp[0][i] = -1; 
        break;
      }
    }
    fi(i,1,n){
      fi(j,1,n){
        if(a[i][j]=='*'){ 
          dp[i][j] = -1; 
          continue;
        }
        if(dp[i-1][j]>0) dp[i][j]+=(dp[i-1][j]%MOD);
        if(dp[i][j-1]>0) dp[i][j]+=(dp[i][j-1]%MOD);
      }
    }
    dp[n-1][n-1]>0 ? cout<< dp[n-1][n-1]%MOD<<endl : cout<<0<<endl;
  }
  return 0;
}