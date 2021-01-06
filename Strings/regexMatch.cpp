// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

bool isMatch(string s,string p){
  int lS = s.size(), lP=p.size();
  vector<vector<bool>> F(lS+1, vector<bool>(lP+1));
  F[0][0]=true;
  fi(i,0,lS+1){
    fi(j,1,lP+1){
      if(i>0){
        
      }
    }
  }
}

int main() 
{  
  string s,p;
  cin>>s>>p;
  cout<<isMatch(s,p)
  return 0; 
} 
