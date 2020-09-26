#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define fi(i,a,n) for(int i=a;i<n;i++)
#define fd(i,a,n) for(ll i=a;i>n;i--)
#define pb push_back
#define fv(i,a) for(auto i:a) 
#define vl vector<ll>

int main(){
    int t;
    cin>>t;
    while(t--){
      ll n;
      cin>>n;
      ll a[n],sum=0;
      fi(i,0,n){
        cin>>a[i];
        sum+=a[i];
      }
     
      if(sum<0){
        cout<<"NO"<<endl;
      }else{
        cout<<"YES"<<endl;
      }
    }    
    return 0;
}