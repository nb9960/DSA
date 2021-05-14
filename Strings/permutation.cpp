// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i <= n; i++) 
#define ll long long

void permute(string s, int l, int r){
  // if(l==r)
  //   cout<<s<<endl;
  // else{
  //   fi(i,l,r){
  //     swap(s[l],s[i]);
  //     permute(s,l+1,r);
  //     // Backtracking
  //     swap(s[l],s[i]);
  //   }
  // }

  // using STL
  sort(s.begin(), s.end());
  do{
    cout<<s<<endl;
  }while(next_permutation(s.begin(), s.end()));
}

int main() 
{  
  string s;
  cin>>s;
  permute(s,0,s.size()-1);
  return 0; 
} 
