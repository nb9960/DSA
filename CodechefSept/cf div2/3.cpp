#include <bits/stdc++.h>
using namespace std;
#define max 10000000
#define ll long long 
#define fi(i,a,n) for(ll i=a;i<n;i++)
#define sortall(x) sort(all(x))
#define all(x) x.begin(), x.end() 
#define fd(i,a,n) for(ll i=a;i>n;i--)
#define pb push_back
#define fv(i,a) for(auto i:a) 
#define vl vector<ll>

int main(){
    int t=1;
    cin>>t;
    while(t--){
      ll n,lt;
      cin>>n>>lt;
      ll s=0;
      vector<pair<ll,ll>> v(n);
      fi(i,0,n){
        cin>>v[i].first;
        v[i].second = i+1;
      }
      sort(v.begin(),v.end());
      
      vl ans;
      for(int i=n-1;i>=0;i--){
        if(s+v[i].first >lt)continue;
        s+=v[i].first;
        ans.pb(v[i].second);
      }
      if(s*2<lt){
        cout<<-1<<endl;
      }
      else{
        cout<<ans.size()<<"\n";
        fi(i,0,ans.size()){
          cout<<ans[i]<<" ";
        }
        cout<<"\n";
      }
    }    
    return 0;
}