// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

// to count the occurences of given element in sorted array
// O(long + count)
// pehla index find kro bs se then left ar right side chal ke dekho

int binarySearch(int a[],int l, int r, int x){
  if (r<l)
    return -1;
  int mid=l+(r-l)/2;
  if(a[mid]==x)
    return mid;

  if(a[mid]>x)
    return binarySearch(a, l, mid-1, x);
  return binarySearch(a,mid+1,r,x);
}

int main() 
{  
  int n,x;
  cin>>n>>x;
  int a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  int ind=binarySearch(a,0,n-1,x);
  if(ind==-1){
    cout<<"0"<<endl;
  }else{
    int left=ind-1, right=ind+1,count=1;
    while(left>=0 && a[left]==x){
      count++; left--;
    }
    while(right< n && a[right]==x){
      count++; right++;
    }
    cout<<count<<endl;
  }
  return 0; 
} 
