#include <bits/stdc++.h>
using namespace std;

// --------- FOR ZERO AND ONE --------------
// int main(){
//   int a[] = {0,1,0,1,1,1};
//   int n = sizeof(a)/sizeof(a[0]);
//   int t1 = 0, t2 = n-1;
//   while(t1<t2){
//     if(a[t1] == 1){
//       swap(a[t1], a[t2]);
//       t2--;
//     }
//     else t1++;
//   }
//   for(int i=0;i<n;i++) cout<<a[i]<<" ";
//   return 0;
// }

// --------- FOR ONE ZERO TWO------
int main(){
  int a[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
  int n = sizeof(a)/sizeof(a[0]);

  int l = 0, mid = 0, h = n-1;
  while(mid<=h){
    if(a[mid]== 0)
      swap(a[l++], a[mid++]);
    else if(a[mid] == 1)
      mid++;
    else
      swap(a[mid], a[h--]);
  }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  return 0;
}