// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

void findPermutations(string s, int l){
  if(l==(s.size()-1)){
    cout<<s<<endl;
    return;
  }
}

int main() 
{  
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  findPermutations(s,0);
  return 0; 
} 
