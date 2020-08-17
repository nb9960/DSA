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

ll getMax(ll a[], ll n){
  ll mx=a[0];
  fi(i,1,n){
    if(a[i]>mx)
      mx=a[i];
  }
  return mx;
}

void countSort(ll a[], ll n, ll exp){
  ll result[n];
  ll i, cnt[10]={0};
  fi(i,0,n){
    cnt[(a[i]/exp)%10]++;
  }
  fi(i,1,10){
    cnt[i]+=cnt[i-1];
  }
  fd(i,n-1,0){
    result[cnt[(a[i]/exp)%10]-1]=a[i];
    cnt[(a[i]/exp)%10]--;
  }
  fi(i,0,n){
    a[i]=result[i];
  }
}

void radixSort(ll a[], ll n){
  ll mmax=getMax(a,n);
  // instead of passing digit number, exp is passed. 
  // exp is 10^i where i is current digit number 
  for(ll exp=1;mmax/exp>0;exp*=10)
    countSort(a,n,exp);
}

int main() { 
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  radixSort(a,n);
  fi(i,0,n){
    cout<<a[i]<<" ";
  }
	return 0; 
} 