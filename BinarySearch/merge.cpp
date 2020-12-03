// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define NA -1

void moveToEnd(int mPlusN[], int size){
  int j=size-1;
  for(int i=size-1;i>=0;i--){
    if(mPlusN[i]!=NA){
      mPlusN[j]=mPlusN[i];
      j--;
    }
  }
}

int merge(int mPlusN[], int N[], int m, int n){
  int i = n; /* Current index of i/p part of mPlusN[]*/
   int j = 0; /* Current index of N[]*/
   int k = 0; /* Current index of output mPlusN[]*/
   while (k < (m + n)) 
   { 
    /* Take an element from mPlusN[] if 
    a) value of the picked element is smaller  
       and we have not reached end of it 
    b) We have reached end of N[] */
    if ((i < (m + n) && mPlusN[i] <= N[j]) || (j == n)) 
    { 
        mPlusN[k] = mPlusN[i]; 
        k++; 
        i++; 
    } 
    else // Otherwise take element from N[] 
    { 
       mPlusN[k] = N[j]; 
       k++; 
       j++; 
    } 
   } 
} 

int main() 
{  
  int mPlusN[]={2,8,NA,NA,NA,13,NA,15,20};
  int N[] = {5, 7, 9, 25}; 
     
  int n = sizeof(N) / sizeof(N[0]); 
  int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;
  moveToEnd(mPlusN,m+n);
  merge(mPlusN,N,m,n);
  fi(i,0,m+n){
    cout<<mPlusN[i]<<" ";
  } 
  cout<<endl;
  return 0; 
} 
