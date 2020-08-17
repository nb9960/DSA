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

void countSort(ll a[], ll k,ll n, ll min){
  ll cnt[k];
  ll output[n];
  fi(i,0,k){
    cnt[i]=0;
  }
  fi(i,0,n){
    cnt[a[i]-min]++;
  }
  fi(i,1,k){
    cnt[i]+=cnt[i-1];
  }
  fd(i,n-1,0){
    output[cnt[a[i]-min]-1]=a[i];
    cnt[a[i]-min]--;
  }
  fi(i,0,n){
    cout<<output[i]<<" ";
  }
}

int main() { 
  ll n;
  cin>>n;
  ll a[n];
  ll max=INT_MIN,min=INT_MAX;
  fi(i,0,n){
    cin>>a[i];
    if(a[i]>max){
      max=a[i];
    }
    if(a[i]<min){
      min=a[i];
    }
  }
  ll k=max-min+1;
  countSort(a,k,n,min);
	return 0; 
} 