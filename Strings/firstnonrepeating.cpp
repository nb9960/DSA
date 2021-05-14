#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(string s){
  int fi[256];
  for(int i=0;i<256;i++)
    fi[i] = -1;
  
  for(int i=0;i<s.size();i++){
    if(fi[s[i]] == -1)
      fi[s[i]] = i;
    else fi[s[i]] = -2;
  }
  
  int res = INT_MAX;
  for(int i=0;i<256;i++){
    if(fi[i] >= 0) 
      res = min(res, fi[i]);
  }
  if(res == INT_MAX) return -1;
  else return res;
}

int main(){
  string str;
    str = "geeksforgeeks";
  int firstIndex = firstNonRepeating(str);
  if (firstIndex == -1)
      cout<<"Either all characters are repeating or string is empty";
  else
      cout<<"First non-repeating character is "<< str[firstIndex];
  return 0;
}