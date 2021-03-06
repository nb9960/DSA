// Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

#include <bits/stdc++.h>
using namespace std;
const int R = 6;
const int C = 5;



int main(){
  bool matrix[R][C] = {{0,1,1,0,1},
                        {1,1,0,1,0},
                        {0,1,1,1,0},
                        {1,1,1,1,0},
                        {1,1,1,1,1},
                        {0,0,0,0,0}}; 
  int sum[R][C];
  for(int i=0;i<R;i++){
    sum[i][0] = matrix[i][0];
  }
  for(int i=0;i<C;i++){
    sum[0][i] = matrix[0][i];
  }
  for(int i=1;i<R;i++){
    for(int j=1;j<C;j++){
      if(matrix[i][j]==1){
        sum[i][j] = min(sum[i-1][j-1], min(sum[i-1][j], sum[i][j-1])) +1;
      }else{
        sum[i][j] = 0;
      }
    }
  }
  int maxSum = 0, indI = 0, indJ=0;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(maxSum<sum[i][j]){
        maxSum = sum[i][j];
        indI = i; indJ= j;
      }
    }
  }
  for(int i = indI;i>indI-maxSum;i--){
    for(int j = indJ; j>indJ-maxSum;j--){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}