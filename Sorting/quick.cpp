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

ll partition(ll a[],ll low,ll high){ 
  ll pivot = a[high]; 
  ll i = low - 1; 
  fi(j,low,high){
    if(a[j]<=pivot){
      i++;
      swap(a[i],a[j]);
    }
  }
  swap(a[i+1],a[high]);
  return i+1;
} 

ll partition_r(ll a[], ll low, ll high){ 
  // Generate a random number in between 
  // low .. high 
  srand(time(NULL)); 
  ll random = low + rand() % (high - low); 
  // Swap A[random] with A[high] 
  swap(a[random], a[high]); 
  return partition(a, low, high); 
} 

void quickSort(ll a[], ll low, ll high){ 
  if (low < high) { 
    ll q= partition_r(a, low, high); 
    quickSort(a, low, q); 
    quickSort(a, q+1, high); 
  } 
} 

int main() { 
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  quickSort(a,0,n-1);
  fi(i,0,n){
    cout<<a[i]<<" ";
  }
	return 0; 
} 