// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

/*
  SORTED ARRAY
 pehle mid check kro fixed point h ya nhi
 hai to vahi print kra do
  else if a[mid]<mid then fixed point right side lie krta h else left
*/

int fixedPoint(int a[], int l, int r){
  if(r<l)
    return -1;
  int mid=l+(r-l)/2;
  if(mid==a[mid])
    return mid;
  if(a[mid]<mid)
    return fixedPoint(a,mid+1,r);
  return fixedPoint(a,l,mid-1);
} 

int main() 
{  
  int n;
  cin>>n;
  int a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  cout<<fixedPoint(a,0,n-1)<<endl;
  return 0; 
} 
