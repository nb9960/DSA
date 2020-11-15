// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 
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
const ll MOD=1000000007;

int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  ll t = 1; 
  cin >> t;

  while (t--) { 
    ll n,m,cnt=0,zero=0,sum=0,mn=1000;
    cin>>n>>m;
    ll a[n][m];
    fi(i,0,n){
      fi(j,0,m){
        cin>>a[i][j];
        if(a[i][j]==0){
          zero++;
        }
        if(a[i][j]<0){
          cnt++;
        }
        mn=min(mn,abs(a[i][j]));
        sum+=abs(a[i][j]);
      }
    }
    if(zero)
      cout<<sum<<endl;
    else if(cnt%2==0)
      cout<<sum<<endl;
    else cout<<sum-(2*abs(mn))<<endl;
  } 

  return 0; 
} 