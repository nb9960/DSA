// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int fac(int n){
  return (n<=1)? 1 : n*fac(n-1);
}

int findRank(string s){
  int total=1,n=s.size();
  fi(i,0,n){
    int less_than=0;
    for(int j=i+1;j<n;j++){
      if(int(s[i])>int(s[j]))
        less_than++;
    }
    vector<int>d_count(52,0);

    for(int j=i;j<n;j++){
      if ((int(s[j]) >= 'A') && int(s[j]) <= 'Z')
        d_count[int(s[j]) - 'A'] ++;
      else
        d_count[int(s[j]) - 'a' + 26] ++;
    }
    int d_fac=1;
    for(int ele : d_count)
      d_fac *= fac(ele);

    total += (fac(n - i - 1) * less_than) / d_fac;
  }
  return total;
}

int main() 
{  
  string s;
  cin>>s;
  cout<<findRank(s);
  return 0; 
} 
