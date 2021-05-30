#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int len){
  int val[len+1];
  val[0] = 0;
  for(int i=1; i<=len; i++){
    int maxm = INT_MIN;
    for(int j=0;j<i;j++){
      maxm = max(maxm, price[j] + val[len-i-1]);
    }
    val[i] = maxm;
  }
  return val[len];
}

int main(){
  int price[] = {1,5,8,9};
  int len = 4;
  cout<<cutRod(price, len)<<endl;
  return 0;
}