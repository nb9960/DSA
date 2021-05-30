#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1]*p[i] for i=1 to n
int matrixChain(int p[], int n){
  int m[n][n];
  /* m[i, j] = Cost  of multiplying matrix A[i]A[i+1]...A[j] = A[i..j]*/

  // cost is 0 when multiplying one matrix so saare diagonal wale 0
  for(int i=1;i<n;i++) m[i][i] = 0;

  // L diagonally move karne ke liye
  for(int L=2;L<n;L++){
    for(int i=1;i<n-L+1;i++){
      int j=i+L-1;
      m[i][j] = INT_MAX;
      for(int k=i;k<=j-1;k++){
        // k mtlb dividing bracket kaha place kiya gaya
        // ex: for (A1A2A3)(A4A5) i=0 j=4 k=2 
        // m[i][k] --> pehle bracket ka btaenge; m[k+1][k] --> dusre ka and 
        // third part dono brackets ke multiplication ka
        m[i][j]= min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
      }
    }
  }
  
  return m[1][n-1]; 
}

int main(){
  int p[] = {1,2,3,4};
  int size = sizeof(p)/sizeof(p[0]);

  cout<<"Minimum no. of multiplications is: "<<matrixChain(p, size)<<endl;
  return 0;
}