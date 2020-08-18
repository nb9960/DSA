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

void bucketSort(float a[], ll n){
  vector<float> b[n];
  fi(i,0,n){
    ll bi=n*a[i];
    b[bi].pb(a[i]);
  }
  fi(i,0,n)
  sort(b[i].begin(),b[i].end());
  ll ind=0;
  fi(i,0,n){
    fi(j,0,b[i].size())
    a[ind++]=b[i][j];
  }
}

int main() { 
  ll n;
  cin>>n;
  float a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  bucketSort(a,n);
  fi(i,0,n){
    cout<<a[i]<<" ";
  }
	return 0; 
} 