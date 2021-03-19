#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {0, 10, 2, -10, -20};
  int n = sizeof(a)/sizeof(a[0]);
  int ans = n+1;

  bool present[n+1] = {false};

  for(int i=0;i<n;i++){
    if(a[i]>0 && a[i]<=n)
      present[a[i]] = true;
  }

  for(int i=1;i<=n;i++){
    if(!present[i]){
      ans = i;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}