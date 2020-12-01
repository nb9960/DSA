// nb_9960
#include <bits/stdc++.h> 
using namespace std; 

/* ceiling of x is the smallest element in array >= x 
and floor is greatest element <= x */

int ceilSearch(int a[], int low, int high, int x){
  int mid;
  // if x<=a[0] like in arr=1,2,3,4 x=0
  if(x<=a[low])
    return low;
  // if x>a[n-1] mtlb usse just bada element 
  // array m h hi nhi to -1
  if(x>a[high])
    return -1;
  mid= (low+high)/2;
  if(a[mid]==x)
    return mid;
  else if(x>a[mid]){
    if(mid+1<=high && x<=a[mid+1])
      return mid+1;
    else return ceilSearch(a,mid+1,high,x);
  }
  else{
    if(mid-1 >=low && x>a[mid-1])
      return mid;
    else ceilSearch(a,low,mid-1,x);
  }
  
}

int floorSearch(int a[], int low, int high, int x){
  if(low>high)
    return -1;
  if(a[high]<=x){
    return high;
  }
  if(a[low]>x)
    return -1;
  int mid = (low+high)/2;
  if(a[mid]==x)
    return mid;
  if(mid>0 && a[mid-1] <= x && x<a[mid])
    return mid-1;
  if(x<a[mid])
    return floorSearch(a,low,mid-1,x);
  return floorSearch(a,mid+1,high,x);
}

int main() 
{  
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int index = ceilSearch(a,0,n-1,x);
  int ind=floorSearch(a,0,n-1,x);
  if(index==-1){
    cout<<"Ceiling doesn't exits"<<endl;
  }
  else cout<<"Ceil of x is : "<<a[index]<<endl;
  if(ind==-1){
    cout<<"Floor doesn't exits"<<endl;
  }
  else cout<<"Floor of x is : "<<a[ind]<<endl;
  return 0; 
} 
