#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "ababbbabbababa";
  int n = s.size();
  // C[i]-->Min no. of cuts needed for a palindrome partitioning of substring s[0..i]
  int C[n];
  /* P[i][j] = true if substring s[i..j] is palindrome, else false
    Note that C[i] is 0 if P[0][i] is true */
  bool P[n][n];
  // Every substring of len 1 is a palindrome
  for(int i=0;i<n;i++) P[i][i] = true;
  /* L is substring length. Build the solution in bottom up manner by
       considering all substrings of length starting from 2 to n. */
  for(int L=2;L<=n;L++){
      // For substring of length L, set different possible starting indexes
      for(int i=0;i<n-L+1;i++){
          int j = i+L-1; // Set ending index
          // If L is 2, then we just need to compare two characters. Else
          // need to check two corner characters and value of P[i+1][j-1]
          if(L==2) P[i][j] = (s[i]==s[j]);
          else P[i][j] = (s[i]==s[j]) && P[i+1][j-1];
      }
  }
  for(int i=0;i<n;i++){
      if(P[0][i]) C[i] = 0;
      else{
          C[i] = INT_MAX;
          for(int j=0;j<i;j++){
              if(P[j+1][i] && (1+C[j] < C[i]))
                  C[i] = 1+C[j];
          }
      }
  }
  cout<<"Minimum no. of cuts needed for palindrome partitioning: "<<C[n-1]<<endl;
  return 0;
}