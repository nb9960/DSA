// nb_9960
#include <bits/stdc++.h> 
using namespace std;

// logic#1 x ko search karo aur check kro uss first occurance wale element k n/2 aage p bhi x hai
// logic#2  (BEST) agar x n/2 ya usse zyada baar h to mid value x hoi hi to vahi check kro bs

int binarySearch(int a[], int low, int high, int x){
  if(high>=low){
    int mid = (low+high)/2;
    /* Check if arr[mid] is the first occurrence of x.
        arr[mid] is first occurrence if x is one of the following
        is true:
        (i) mid == 0 and arr[mid] == x
        (ii) arr[mid-1] < x and arr[mid] == x
    */
    if ( (mid == 0 || x > a[mid-1]) && (a[mid] == x) )
        return mid;
    else if (x > a[mid])
        return binarySearch(a, (mid + 1), high, x);
    else
        return binarySearch(a, low, (mid -1), x);
  }
  return -1;
}

bool isMajority(int a[], int n, int x){
  int i=binarySearch(a,0,n-1,x);
  // x hai hi nahi array mein
  if(i==-1)
    return false;
  
  // check n/2 p bhi vah element hai to true
  if(((i+n/2) <= (n-1)) && a[i+n/2]==x)
    return true;
  else return false;
}

int main() 
{  
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  if(isMajority(a,n,x)){
    cout<<"True"<<endl;
  }
  else cout<<"False"<<endl;
  return 0; 
} 