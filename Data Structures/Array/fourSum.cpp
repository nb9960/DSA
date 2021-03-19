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
  int a[] = {10,20,30,40,1,2};
  int n = sizeof(a)/sizeof(a[0]);
  int k = 91;
  
  unordered_map<int, pair<int, int>> mp;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      mp[a[i]+a[j]] = {i,j};
    }
  }

  int temp[n];
  for(int i=0;i<n;i++) temp[i] =0;

  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      int sum = a[i] + a[j];
      if(mp.find(k-sum) != mp.end()){
        pair<int, int> p = mp[k-sum];
        if(p.F!=i && p.F!=j && p.S!=i && p.S!=j && temp[i]==0 && temp[j]==0 && temp[p.F]==0 && temp[p.S] ==0){
          cout<<a[i]<<" "<<a[j]<<" "<<a[p.F]<<" "<<a[p.S]<<endl;
          temp[i]=1; temp[j]=1; temp[p.F] = 1; temp[p.S] = 1;
          break;
        }
      }
    }
  }
  return 0; 
} 
