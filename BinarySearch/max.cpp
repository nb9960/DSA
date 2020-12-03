// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

/*
To find max element in an array which is first increasing and then decr
jaha break point aega vahi max hoga
for max wala point a[i]>a[i-1] && a[i]>a[i+1]
*/

int findMax(int a[], int l, int r){
  // agar ek hi element ho to 
  if(l==r)
    return a[l];
  // agar 2 hi element ho to
  if((l+1==r) && a[l]>=a[r])
    return a[l];
  if((l+1==r) && a[l]<a[r])
    return a[r];
  // generalising
  if(r<l)
    return -1;
  int mid=(l+r)/2;
  if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
    return a[mid];
  if(a[mid]>a[mid-1] && a[mid]<a[mid+1])
    return findMax(a,mid+1,r);
  return findMax(a,l,mid-1);
}

int main() 
{  
  int n;
  cin>>n;
  int a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  cout<<findMax(a,0,n-1);
  return 0; 
} 
