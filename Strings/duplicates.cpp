// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

void printDuplicates(string s){
  int cnt[256];
  memset(cnt,0,sizeof(cnt));
  fi(i,0,s.size()){
    cnt[s[i]]++;
  }
  fi(i,0,256){
    if(cnt[i]>1)
      printf("%c, count = %d \n", i, cnt[i]);
  }
}

int main() 
{  
  string s="test string";
  // cin>>s;
  printDuplicates(s);
  return 0; 
} 
