/* Find Min element in sorted & rotated array

Idea: Min wale case m hi bs left wala > hoga
Mid value check kro 3 possible cases:
1. a[mid]<a[last] === left side
2. else right side p

nb_9960 */
#include <bits/stdc++.h> 
using namespace std; 

int findMin(int arr[], int l, int r){
  // agar rotated hi na ho to
  if(r<l)
    return arr[0];

  // ek hi element ho to
  if(l == r)
    return arr[l];

  int mid = l+(r-l)/2;

  // agar mid+1 min hai to
  if(mid<r && arr[mid+1] < arr[mid])
    return arr[mid+1];
  
  // agar mid min hai to
  if(mid>l && arr[mid] < arr[mid-1])
    return arr[mid];

  if(arr[r] > arr[mid])
    return findMin(arr, l, mid-1);
  return findMin(arr, mid+1, r);
}

int main() 
{  
  int arr[]={5,6,1,2,3,4};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<findMin(arr, 0 , n-1);
  
  return 0; 
} 
