// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  int n;
  cin>>n;
  int a[n];
  int max_so_far=0,max_ending_here=0;
  fi(i,0,n){
    cin>>a[i];
    max_ending_here += a[i];
    if(max_so_far<max_ending_here){
      max_so_far = max_ending_here;
    }
    if(max_ending_here<0)
      max_ending_here = 0;
  }
  cout<<max_so_far<<endl;
  return 0; 
} 
