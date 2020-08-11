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

ll parent(ll i){

}

ll heapMax(ll a[]){
  return a[0];
}

ll extractMax(ll a[], ll n){
  if(n<1){
    return;
  }
  ll max=a[0];
  a[0]=a[n];
  n--;
  maxHeap(a,n,0);
  return max;
}

void increaseKey(ll a[], ll i,ll key){
  if(key<a[i]){
    return;
  }
  a[i]=key;
  while(i>1 && a[parent(i)]<a[i]){
    swap(a[i],a[parent(i)]);
    i=parent(i);
  }
}

void maxInsert(ll a[],ll n, ll key){
  n++;
  a[n]=INT_MIN;
  increaseKey(a,n,key);
}

void maxHeap(ll a[], ll n, ll i){
  ll largest=i;
  ll l=2*i+1;
  ll r=2*i+2;
  if(l<n && a[l]>a[largest]){
    largest=l;
  }
  if(r<n && a[r]>a[largest]){
    largest=r;
  }
  if(largest!=i){
    swap(a[i],a[largest]);
    maxHeap(a,n,largest);
  }
}

void heapSort(ll a[], ll n){
  fd(i,floor(n/2),0){
    maxHeap(a,n,i);
  }
  fd(i,n-1,1){
    swap(a[0],a[i]);
    maxHeap(a,i,0);
  }
}

int main() { 
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  heapSort(a,n);
  fi(i,0,n){
    cout<<a[i]<<" ";
  }
	return 0; 
} 