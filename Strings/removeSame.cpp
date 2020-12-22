// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 

// Remove characters from the first string which 
// are present in the second string

void rem(string str,string mask){
  bool cnt[256];
  vector<char>res;
  memset(cnt,false,sizeof(cnt));
  for(int i=0;mask[i];i++){
    cnt[mask[i]]=true;
  }
  fi(i,0,str.size()){
    if(cnt[str[i]]==false){
      res.push_back(str[i]);
    }
  }
  fi(i,0,res.size())
  cout<<res[i];
  cout<<endl;
}

int main() 
{  
  string str,mask;
  cin>>str>>mask;
  rem(str,mask);
  return 0; 
} 
