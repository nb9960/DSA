#include <bits/stdc++.h>
using namespace std;

void perm(string ans, string s, int l, int r){
  if(l>r){
    cout<<ans<<endl;
    return;
  }else{
    for(int i=l;i<=r;i++){
      if(s[l]==s[i] && l!=i)
        continue;
      swap(s[l], s[i]);
      perm(ans+s[l], s, l+1, r);
    }
  }
}

int main(){
  string s;
  cin>>s;
  sort(s.begin(), s.end());
  perm("", s, 0, s.size()-1);
  return 0;
}