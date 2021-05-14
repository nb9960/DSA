#include <bits/stdc++.h>
using namespace std;

int main(){
  int p[] = {7,1,5,3,6,4};
  int n = sizeof(p)/sizeof(p[0]);
  int cost = 0, maxCost = 0;
  
  int min_price = p[0];
  for(int i=0;i<n;i++){
    min_price = min(min_price, p[i]);
    cost = p[i] - min_price;
    maxCost = max(maxCost, cost);
  }
  cout<<maxCost<<endl;
  return 0;
}