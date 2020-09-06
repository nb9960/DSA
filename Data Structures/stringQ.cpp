// Author:Nishtha

#include <bits/stdc++.h> 
using namespace std; 
  
void perm(string s,int k){
  static int a[10]={0};
  static char res[10];
  if(s.size()==0){
    cout<<k<<endl;
    return;
  }else{
    for(int i=0;i<s.size();i++){
      if(a[i]==0)
      {
        res[k]=s[i];
        a[i]=1;
        perm(s,k+1);
        a[i]=0;
      }
    }
  }
}

// Drive Code 
int main() 
{  
  string s="ABC";
  perm(s,0);

  return 0; 
} 
