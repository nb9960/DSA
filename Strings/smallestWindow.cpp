/* 
Find the smallest window in a string 
containing all characters of another string 
*/

// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

string findSubstring(string s, string substr){
  int n1 = s.length(), n2 = substr.length();
  if(n1<n2){
    cout<<"No such window exists";
    return "";
  }
  int hash_substr[256]={0};
  int hash_s[256]={0};

  fi(i,0,n2)
    hash_substr[substr[i]]++;
  int start=0, start_ind=-1, min_len=INT_MAX;
  int cnt=0;
  fi(j,0,n1){
    hash_s[s[j]]++;
    if(hash_substr[s[j]]!=0 && hash_s[s[j]]<=hash_substr[s[j]])
      cnt++;
    if(cnt==n2){
      while(hash_s[s[start]]>hash_substr[s[start]] || hash_substr[s[start]]==0){
        if(hash_s[s[start]]>hash_substr[s[start]])
          hash_s[s[start]]--;
        start++;
      }
      int len_win = j-start+1;
      if(min_len>len_win){
        min_len = len_win;
        start_ind = start;
      }
    }
  }
  if(start_ind == -1){
    cout<<"No such window exists";
    return "";
  }
  return s.substr(start_ind, min_len);
}

int main() 
{  
  string s="this is a test string",substr="tist";
  // cin>>s>>substr;
  cout<<"Smallest Window is: "<<findSubstring(s,substr);
  return 0; 
} 
