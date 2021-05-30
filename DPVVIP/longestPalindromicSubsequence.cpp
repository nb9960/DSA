#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "GEEKS FOR GEEKS";
  int n = s.size();

  int L[n][n];
  // strings of length 1 are palindromes of len 1
  for(int i=0;i<n;i++) L[i][i] = 1;
  // cl is length of substring
  for(int cl=2; cl<=n; cl++){
    for(int i=0; i<n-cl+1;i++){
      int j=i+cl-1;
      if(s[i]==s[j] && cl==2)
        L[i][j] = 2; //len 2 hai aur dono equal hai
      else if(s[i] == s[j])
        L[i][j] = L[i+1][j-1] + 2;
      else L[i][j] = max(L[i][j-1], L[i+1][j]);
    }
  }
  cout<<"The length of the longest palindromic subsequence: "<<L[0][n-1]<<endl;

  return 0;
}