#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 6, m = 7;
  // cin>>n>>m;
  string x = "AGGTAB", y = "GXTXAYB";
  // cin>>x>>y;
  int L[n+1][m+1];

  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i==0 || j==0) L[i][j] = 0;
      else if(x[i-1] == y[j-1])
        L[i][j] = 1+L[i-1][j-1];
      else L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
  }

  cout<<L[n][m]<<endl;
  int ind = L[n][m];
  char lcs[ind + 1];
  lcs[ind] = '\0';
  int i=n, j=m;
  while(i>0 && j>0){
    if(x[i-1] == y[j-1]){
      lcs[ind-1] = x[i-1];
      i--; j--; ind--;
    }
    else if(L[i-1][j] > L[i][j-1]) i--;
    else j--;
  }
  cout<<"LCS of "<<x<<" and "<<y<<" is "<<lcs;
  return 0;
}