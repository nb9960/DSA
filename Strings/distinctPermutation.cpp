// nb_9960

/* .............GOOD ONE..........*/

#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

void findPermutations(string s, int l){
  if(l==(s.size()-1)){
    cout<<s<<endl;
    return;
  }
  char pre = '*';
  fi(j,l,s.size()){
    string tmp = s;
    if(j>l && tmp[l]==tmp[j])
      continue;
    if(pre != '*' && pre == s[j])
      continue;
    swap(tmp[l],tmp[j]);
    pre =s[j];
    findPermutations(tmp, l+1);
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
