#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {2, 3, 3, 5, 3, 4, 1, 7};
  int n = sizeof(a)/sizeof(a[0]), k = 8;

  // increament a[a[i]%k] by k
  // k is added max no of times at the index equal to max repeating element 
  for(int i=0;i<n;i++)
    a[a[i]%k] += k;
  
  int maxm = a[0], maxInd = 0;
  // find maximum value. Index of max value is max repeating element
  for(int i=1;i<n;i++){
    if(maxm < a[i]){
      maxm = a[i]; maxInd = i;
    }
  }
  cout<<maxInd<<endl;
  return 0;
}