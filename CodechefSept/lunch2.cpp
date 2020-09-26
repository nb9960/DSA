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
    int t=1;
    cin>>t;
    while(t--){
      ll n;
      cin>>n;
      ll b[n];
      fi(i,0,n)
      cin>>b[i];
      bool flag=true;
      fi(i,0,n)
      {
        if((i+1)%b[i]!=0)
        {
          flag=false;
          break;
        }
      }
      if(flag)
      cout<<"YES"<<endl;
      else
      {
        cout<<"NO"<<endl;
      }
      
    }    
    return 0;
}