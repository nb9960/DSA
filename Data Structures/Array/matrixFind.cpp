#include <bits/stdc++.h>
using namespace std;

int main(){
  int mat[4][4] = { { 10, 20, 30, 40 },
                    { 15, 25, 35, 45 },
                    { 27, 29, 37, 48 },
                    { 32, 33, 39, 50 } };
  int x=29, n=4;
  int ans1=-1, ans2=-1;
  // if(n==0) ans = -1;
  int smallest = mat[0][0], largest = mat[n-1][n-1];
  int i=0, j=n-1;
  while(i<n && j>=0){
    if(mat[i][j] == x) {
      ans1=i; ans2=j;
    }
    if(mat[i][j] > x) j--;
    else i++;
  }

  cout<<ans1<<" "<<ans2<<endl;
  return 0;
}