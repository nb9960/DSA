// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int fact(int n){
  return (n<=1)?1:n*fact(n-1);
}

void populateAndIncreaseCnt(int* cnt, string s){
  int i=0;
  for(i=0;s[i];i++)
    cnt[s[i]]++;
  for(i=1;i<256;i++)
    cnt[i]+=cnt[i-1];
}

void updateCnt(int* cnt, char ch){
  int i;
  for(i=ch;i<256;i++)
    cnt[i]--;
}

int findRank(string s){
  int n=s.size();
  int mul=fact(n);
  int rank=1,i;
  int cnt[256]={0};

  populateAndIncreaseCnt(cnt,s);

  for(i=0;i<n;i++){
    mul/=n-i;
    rank+=cnt[s[i]-1]*mul;

    updateCnt(cnt,s[i]);
  }
  return rank;
}

int main() 
{  
  string s;
  cin>>s;
  cout<<findRank(s);
  return 0; 
} 
