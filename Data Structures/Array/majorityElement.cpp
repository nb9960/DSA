#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
  int n = sizeof(a)/sizeof(a[0]);

  // METHOD - 1 :: HASHMAP store the count of elements if count > n/2 print the element
  
  // METHOD - 2:: Sort the array and check frequency 
  
  // METHOD -3 :: moore's voting algorithm- time: O(n) space: O(1)
  /*
    agar next el same h to cnt++ else cnt--
    if cnt==0 change majInd and cnt=1
    fir check kro majority wala sahi m major h ya nhi
  */

  int majInd = 0, count =1, maj;
  bool isMajor = false;
  for(int i=1;i<n;i++){
    if(a[majInd] == a[i]) count++;
    else count--;
    if(count == 0){
      majInd = i; count = 1;
    }
  }
  maj = a[majInd];
  count = 0;
  for(int i=0;i<n;i++){
    if(a[i]==maj) count++;
  }
  if(count > n/2) isMajor = true;
  if(isMajor) cout<<maj<<endl;
  else cout<<"No major element"<<endl;
  return 0;
}