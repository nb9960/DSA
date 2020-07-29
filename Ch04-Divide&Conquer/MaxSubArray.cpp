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

// FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
//   - Time: O(n)
// FIND-MAXIMUM-SUBARRAY(A, low, high)
//   - Time: O(n lg n)
// BRUTE-FORCE-FIND-MAXIMUM-SUBARRAY(A)
//   - Time: O(n^2)
// ITERATIVE-FIND-MAXIMUM-SUBARRAY(A)
//   - Time: O(n)


ll max(ll a,ll b, ll c){
  return max(max(a,b),c);
}

ll maxCrossingSum(ll a[], ll low, ll mid, ll high){
  ll sum=0;
  ll left_sum=INT_MIN;
  // left of mid wale part se dekho
  fd(i,mid,low){
    sum+=a[i];
    if(sum>left_sum){
      left_sum=sum;
    }
  }
  // same right of mid wale part se dekho
  sum=0;
  ll right_sum=INT_MIN;
  fi(i,mid+1,high+1){
    sum+=a[i];
    if(sum>right_sum){
      right_sum=sum;
    }
  }
  return max(left_sum+right_sum, left_sum, right_sum);
}

// Returns sum of maximum sum subarray in a[low...high]
ll maxSubArraySum(ll a[], ll low, ll high){
  // Base Case: Only one element
  if(low==high){
    return a[low];
  }
  ll mid=(low+high)/2;
  /* Return maximum of following three possible cases 
      a) Maximum subarray sum in left half 
      b) Maximum subarray sum in right half 
      c) Maximum subarray sum such that the subarray crosses the midpoint */
  return max(maxSubArraySum(a,low,mid),
            maxSubArraySum(a,mid+1,high),
            maxCrossingSum(a,low,mid,high));
}

int main() { 
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  ll max_sum=maxSubArraySum(a,0,n-1);
  cout<<max_sum;
	return 0; 
} 