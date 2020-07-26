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

void merge(ll a[], ll l, ll m, ll r){
  ll n1=m-l+1;
  ll n2=r-m;
  ll L[n1], R[n2];
  fi(i,0,n1){
    L[i]=a[l+i];
  }
  fi(j,0,n2){
    R[j]=a[m+j+1];
  }
  ll i=0,j=0,k=l;
  while(i<n1 && j<n2){
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }
    else{
      a[k]=R[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    a[k]=L[i];
    i++;
    k++;
  }
  while(j<n2){
    a[k]=R[j];
    j++;
    k++;
  }
}

void mergeSort(ll a[], ll l, ll r){
  if(l<r){
    ll m=l+(r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
  }
}

int main() { 
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  mergeSort(a, 0, n-1);
  fi(i,0,n){
    cout<<a[i]<<" ";
  }
	return 0; 
} 