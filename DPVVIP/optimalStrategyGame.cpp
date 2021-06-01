#include <bits/stdc++.h>
using namespace std;

/*
There are two choices:  F(i,j) is max of these choices
  1.The user chooses the ‘ith’ coin with value ‘Vi’: The opponent either chooses (i+1)th coin or jth coin. 
  The opponent intends to choose the coin which leaves the user with minimum value i.e. The user can collect 
  the value Vi + min(F(i+2, j), F(i+1, j-1) ). 
  2. The user chooses the ‘jth’ coin with value ‘Vj’: The opponent either chooses ‘ith’ coin or ‘(j-1)th’ coin. 
  The opponent intends to choose the coin which leaves the user with minimum value, i.e. the user can collect 
  the value Vj + min(F(i+1, j-1), F(i, j-2) ).
*/

int optimalStrategyOfGame(int* arr, int n){
  int table[n][n];
  // diagonally chalo
  for(int L=0;L<n;L++){
    for(int i=0, j=L; j<n;i++, j++){
      if(j==i)  // arthat 1 hi element h to vahi pick hoga
        table[i][j] = arr[i];

      else if(j == i+1) // arthat 2 hi element hai toh dono ka max hi pick krega
        table[i][j] = max(arr[i], arr[j]);

      // max ka pehla part : ith select kiya user ne; dusra part: jth select kiya
      else table[i][j] = max( (arr[i] + min(table[i+2][j], table[i+1][j-1])), 
                              (arr[j] + min(table[i+1][j-1], table[i][j-2])));
    }
  }
  return table[0][n-1];
}

int main(){
  int arr1[] = { 8, 15, 3, 7 };
  int n = sizeof(arr1) / sizeof(arr1[0]);
  printf("%d\n", optimalStrategyOfGame(arr1, n));

  int arr2[] = { 2, 2, 2, 2 };
  n = sizeof(arr2) / sizeof(arr2[0]);
  printf("%d\n", optimalStrategyOfGame(arr2, n));

  int arr3[] = { 20, 30, 2, 2, 2, 10 };
  n = sizeof(arr3) / sizeof(arr3[0]);
  printf("%d\n", optimalStrategyOfGame(arr3, n));
  return 0;
}