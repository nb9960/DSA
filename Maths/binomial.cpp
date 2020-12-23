// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int binomialCoeff(int n, int k){
  int res = 1;
  if(k>(n-k))
    k = n-k;
  fi(i,0,k){
    res *= (n-i);
    res /= (i+1);
  }
  return res;
}

int main() 
{  
  int n,k;
  cin>>n>>k;
  cout<<"Value of C("<<n<<", "<<k<<") is: "<<binomialCoeff(n,k);
  return 0; 
} 
