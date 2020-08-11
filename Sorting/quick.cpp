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
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  
  fi(i,0,n){
    cout<<a[i]<<" ";
  }
	return 0; 
} 