// nb_9960
#include <bits/stdc++.h> 
using namespace std;

/*
3 type ke input-output:
  1. Input palindrome hai aur saare 9s hai
      Ex: "9 9 9" output- 1 0 0 1
      Todo: n+1 ki length ka array bana lo jisme dono end 1 ho aur beech m sab 0
  2. Input palindrome nahi hai
      Ex: "1 2 3 4" output- "1 3 3 1" 
*/
int main() 
{  
  // int num[] = {9,4,1,8,7,9,7,8,3,2,2};
  int n;
  cin>>n;
  int a[n];
  bool areAllNine = true;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]!=9) areAllNine = false; 
  }
  if(areAllNine){
    for(int i=0;i<n+1;i++){
      if(i==0 || i==n){
        cout<<"1 ";
      }else cout<<" 0 ";
    }
  }else{
    int mid = n/2;
    bool leftsmaller = false;
    int i = mid -1;
    int j = (n%2) ? mid+1 : mid;
    // agar middle wale same hai to ignore karo unhe
    while(i>=0 && a[i]==a[j])
      i--, j++;
    if(i<0 || a[i]<a[j])
      leftsmaller = true;
    
    // copy the mirror of left to right
    while(i>=0){
      a[j] = a[i];
      j++; i--;
    }

    if(leftsmaller){
      int carry = 1;
      i = mid-1;
      if(n%2 == 1){
        a[mid] += carry;
        carry = a[mid]/10;
        a[mid] %= 10;
        j = mid+1;
      }else j=mid;
      
      while(i>=0){
        a[i] += carry;
        carry = a[i]/10;
        a[i] %= 10;
        a[j++] = a[i--];
      }
    }

    for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
    }
  }
  return 0; 
} 
