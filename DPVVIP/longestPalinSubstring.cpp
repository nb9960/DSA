#include <bits/stdc++.h>
using namespace std;

int longestPalSub(string s){
  int maxLen = 1, start = 0, n = s.size(), low, high;
  
  // one by one consider every char as center point of even and odd len palindromes
  for(int i=1;i<n;i++){
    // find the longest even length palindrome with center points as i-1 & i
    low = i-1; high = i;
    while(low>=0 && high<n && s[low] == s[high]){
      if(high-low+1 > maxLen){
        start = low;
        maxLen = high-low+1;
      }
      low--;
      high++;
    }

    // find longest odd len palindrome with center point as i
    low = i-1; high = i+1;
    while(low>=0 && high<n && s[low] == s[high]){
      if(high-low+1 > maxLen){
        start = low;
        maxLen = high-low+1;
      }
      low--;
      high++;
    }
  }
  cout << "Longest palindrome substring is: ";
  for (int i=low; i<=high; ++i)
    cout << s[i];

  return maxLen;
}

int main(){
  string s= "forgeeksskeegfor";
  int n = s.size();

  // constant space approach
  cout<<longestPalSub(s)<<endl;

  // dp[i][j]=true agar i...j tk ki substring palindrome hai
  // if dp[i+1...j-1] = true && s[i] = s[j] then dp[i][j] =true
  bool dp[n][n];
  memset(dp, 0, sizeof(dp));
  int maxLen = 1;
  for(int i=0;i<n;i++) dp[i][i] = true;
  
  // len=2 wali ke liye 
  int start = 0;
  for(int i=0;i<n-1;i++){
    if(s[i] == s[i+1]){
      dp[i][i+1] = true;
      start = i; maxLen = 2;
    }
  }

  // k is len of substring
  for(int k=3;k<=n;k++){
    // fix starting index
    for(int i=0;i<n-k+1;i++){
      // get ending index from starting index i and len k
      int j = i+k-1;
      // checking for s[i..j]
      if(dp[i+1][j-1] && s[i]==s[j]){
        dp[i][j] = true;
        if(k>maxLen){
          start = i; maxLen = k;
        }
      }
    }
  }
  cout<<"Length is: "<<maxLen<<endl;

  return 0;
}