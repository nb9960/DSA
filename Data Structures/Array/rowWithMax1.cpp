#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

int first(bool a[], int low, int high){
  if(high>=low){
    int mid = low +(high-low)/2;
    if((mid == 0 || a[mid-1] == 0) && a[mid] ==1){
      return mid;
    }else if(a[mid]==0){
      return first(a, mid+1, high);
    }else{
      return first(a, low, mid-1);
    }
  }
  return -1;
}

int main(){
  bool mat[R][C] = { {0, 0, 0, 1}, 
                    {0, 1, 1, 1}, 
                    {1, 1, 1, 1}, 
                    {0, 0, 0, 0}};
  int max_row_ind = 0, max = -1;
  int ind;
  for(int i=0;i<R;i++){
    ind = first(mat[i], 0, C-1);
    if(ind != -1 && C-ind > max){
      max = C-ind;
      max_row_ind = i;
    }
  }
  cout<<max_row_ind<<endl;
  return 0;
}