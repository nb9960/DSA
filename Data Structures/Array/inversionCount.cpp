#include <bits/stdc++.h>
using namespace std;

int mmerge(int a[], int temp[], int left, int mid, int right){
  int i=left, j=mid, k=left, inv_count = 0;
  while((i <= mid-1) && (j<=right)){
    if(a[i] <= a[j]) temp[k++] = a[i++];
    else{
      temp[k++] = a[j++];
      inv_count += (mid - i);
    }
  }
  while(i <= mid -1)
    temp[k++] = a[i++];
  while(j <= right)
    temp[k++] = a[j++];
  for(i=left;i<=right;i++)
    a[i] = temp[i];
  return inv_count;
}

int mergeSort(int a[], int temp[], int left, int right){
  int mid, inv_count = 0;
  if(left<right){
    mid = (left + right)/2;
    inv_count += mergeSort(a,temp, left, mid);
    inv_count += mergeSort(a, temp, mid+1, right);
    inv_count += mmerge(a, temp, left, mid+1, right);
  }
  return inv_count;
}

int main(){
  int a[] = {1,20,6,4,5};
  int n = sizeof(a)/sizeof(a[0]);
  int temp[n];
  int ans = mergeSort(a, temp, 0, n-1);
  cout<<ans<<endl;
  return 0;
}