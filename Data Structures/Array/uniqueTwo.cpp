// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<ll, ll> pl; 
typedef vector<ll> vl; 
typedef vector<pl> vpii; 
#define sz(a) int((a).size())
#define tr(c,i) for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) (c.find(x) != c.end())
#define cpresent(c,x) (find(all(c),x) != c.end())

int main() 
{  
    int a[] = {2,4,7,9,2,4};
    int x = a[0], n=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n;i++){
      x = x^a[i];
    }
    int set_bit = x & ~(x-1), first = 0, second = 0;
    for(int j=0;j<n;j++){
      if(set_bit & a[j]){
        first ^= a[j];
      }else{
        second ^= a[j];
      }
    }
    cout<<first<<" "<<second<<endl;
  return 0; 
} 
