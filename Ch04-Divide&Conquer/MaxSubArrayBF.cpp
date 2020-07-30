#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define fi(i,a,n) for(ll i=a;i<n;i++)
#define fd(i,a,n) for(ll i=a;i>=n;i--)
#define pb push_back
#define fv(i,a) for(auto i:a) 
#define vi vector<int>

// max sub Array problem using brute force- Time complexity O(n^2)
int main() { 
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  ll low,high,max_sum=INT_MIN;
  fi(l,0,n){
    ll temp_sum=0;
    fi(h,l,n){
      temp_sum+=a[h];
      if(temp_sum>max_sum){
        max_sum=temp_sum;
        low=l;
        high=h;
      }
    }
  }
  cout<<low+1<<" "<<high+1<<" "<<max_sum<<endl;
	return 0; 
} 