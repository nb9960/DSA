// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 
#define pb push_back
#define fd(i,n,a) for(int i=n;i>=a;i--)

void reverseWords(string s){
  vector<string>tmp;
  string str="";
  fi(i,0,s.length()){
    if(s[i]==' '){
      tmp.pb(str);
      str="";
    }
    else str+=s[i];
  }
  tmp.pb(str);
  fd(i,tmp.size()-1,0){
    cout<<tmp[i]<<" ";
  }
  cout<<endl;
}

int main() 
{  
  string s="i like this program very mch";
  // cin>>s;
  reverseWords(s);
  return 0; 
} 
