#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define fi(i,a,n) for(ll i=a;i<n;i++)
#define fd(i,a,n) for(ll i=a;i>=n;i--)
#define pb push_back
#define fv(i,a) for(auto i:a) 
#define vi vector<int>

int main() { 
  string s;
  cin>>s;
  bool b[s.size()],b0=true,allCap=true,allSmall=true,firstCap=true;
  if(s[0]>=97 && s[0]<=122){
    b0=false;
  }
  fi(i,1,s.size()){
    if(s[i]>=97 && s[i]<=122){
      allCap=false;
    }else if(s[i]>=65 && s[i]<=90){
      allSmall=false;
      firstCap=false;
    }
  }
  if((b0 && firstCap) || (b0 && allCap) || (!b0 && allSmall)){
    cout<<"True"<<endl;
  }else{
    cout<<"False"<<endl;
  }

	return 0; 
} 