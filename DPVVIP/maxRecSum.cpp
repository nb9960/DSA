#include <bits/stdc++.h>
using namespace std;
#define row 4
#define col 5

int kadane(int* arr, int* start, int* finish, int n){
  int sum = 0, maxSum = INT_MIN, localStart = 0;
  *finish = -1;
  for(int i=0;i<n;i++){
    sum += arr[i];
    if(sum<0){
      sum = 0;
      localStart = i+1;
    }
    else if(sum>maxSum){
      maxSum = sum;
      *start = localStart;
      *finish = i;
    }
  }
  if(*finish != -1) return maxSum;
  maxSum = arr[0];
  *start = *finish = 0;
  for(int i=1;i<n;i++){
    if(arr[i]>maxSum){
      maxSum = arr[i];
      *start = *finish = i;
    }
  }
  return maxSum;
}

int main(){
  int m[row][col] = {{1,2,-1,-4,-20},
                      {-8,-3,4,2,1},
                      {3,8,10,1,3},
                      {-4,-1,1,7,-6}};

  int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
  int temp[row], sum, start, finish;

  for(int left = 0;left<col;left++){
    memset(temp,0,sizeof(temp));
    for(int right = left;right<col;right++){
      for(int i=0;i<row;i++)
        temp[i] += m[i][right];
    
      sum = kadane(temp, &start, &finish, row);
      if(sum>maxSum){
        maxSum = sum;
        finalLeft = left;
        finalRight = right;
        finalTop = start;
        finalBottom = finish;
      }
    }
  }

  return 0;
}