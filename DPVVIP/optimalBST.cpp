#include <bits/stdc++.h>
using namespace std;

int optimalBST(int keys[], int freq[], int n, int presum[]){
  // cost[i][j] --> optimal cost of BST that can be formed form keys[i] to keys[j]
  // we want cost[0][n-1]
  int cost[n][n];

  //for single key cost is equal to freq of key
  for(int i=0;i<n;i++) cost[i][i] = freq[i];

  // L represents length of chain
  for(int L=2;L<=n;L++){
    // i--> row no. in cost[][]
    for(int i=0;i<=n-L+1;i++){
      int j=i+L-1; // col number
      cost[i][j] = INT_MAX;

      // saare i to j mei aane wali keys (aka keys[i..j]) ko root bnake dekho
      // r--> current root wali key ka index
      for(int r=i;r<=j;r++){
        // c--> cost when keys[r] becomes root of subtree
        int c = ((r>i) ? cost[i][r-1] : 0) + ((r<j) ? cost[r+1][j] : 0) + ((i==0) ? presum[j] : presum[j] - presum[i-1]);
        if(c < cost[i][j]) cost[i][j] = c;
      }
    }
  }
  return cost[0][n-1];
}

int main(){
  int keys[] = {10,12,20};
  int freq[] = {34,8,50};
  int n = sizeof(keys)/sizeof(keys[0]);
  int presum[n];
  presum[0]= freq[0];
  for(int i=1;i<n;i++)
    presum[i] = presum[i-1] + freq[i];

  cout<<"Cost of optimal BST is: "<< optimalBST(keys, freq, n, presum)<<endl;
  return 0;
}