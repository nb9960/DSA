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

ll randomizedPartition(ll a[], ll low, ll high){ 
  // Generate a random number in between 
  // low .. high 
  srand(time(NULL)); 
  ll random = low + rand() % (high - low); 
  // Swap A[random] with A[high] 
  swap(a[random], a[high]); 
  return partition(a, low, high); 
} 

ll randomizedSelect(ll a[],ll p, ll r, ll i){
  if (p==r){
    return a[p];
  }
  ll q=randomizedPartition(a,p,r);
  ll k=q-p+1;
  if(i==k){
    return a[q];
  }else if(i<k){
    return randomizedSelect(a,p,q-1,i);
  }else return randomizedSelect(a,q+1,r,i-k);
}

int main() { 
  ll n,el;
  cin>>n>>el;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  ll elSmallest=randomizedSelect(a,1,n,el);
  cout<<elSmallest<<endl;
	return 0; 
} 