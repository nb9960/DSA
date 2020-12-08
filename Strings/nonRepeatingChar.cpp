/* 
Given a string and a number k, find the k’th non-repeating character in the string
by only doing only one traversal of input string in O(n)
*/

// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

int main() 
{  
  int cnt[256], ind[256],k=3;
  fi(i,0,256){
    cnt[i]=0;
    ind[i]=INT_MAX;
  }
  string s="geeksforgeeks";
  fi(i,0,s.size()){
    cnt[s[i]]++;
    if(cnt[s[i]]==1)
      ind[s[i]]=i;
    if(cnt[s[i]]==2)
      ind[s[i]]=INT_MAX;
  }
  sort(ind,ind+256);
  if(ind[k-1]!=INT_MAX)
    cout<<s[ind[k-1]];
  else cout<<"There are less than k non-repeating chracters";

  return 0; 
} 
