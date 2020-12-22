/*
Longest substring with non repeating char
by sliding window technique in O(n^2) time complexity
*/

// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int longestUniqueSubsttr(string s){
  int n=s.size(),res=0;
  fi(i,0,n){
    vector<bool>visited(256);
    fi(j,i,n){
      if(visited[s[j]]==true)
        break;
      else{
        res=max(res,j-i+1);
        visited[s[j]]=true;
      }
    }
    visited[s[i]]=false;
  }
  return res;
}

int main() 
{  
  string s;
  cin>>s;
  int len = longestUniqueSubsttr(s); 
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len; 
  return 0; 
} 
