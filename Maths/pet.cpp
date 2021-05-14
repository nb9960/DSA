#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  for(int i=1;i<=t;i++){
    cout<<"Case #"<<i<<": ";
    int n;
    cin>>n;
    string s = "A";
    vector<int> v;
    for(int j=0;j<n;j++){
      int l;
      cin>>l;
      v.push_back(l);
    }
    for(int j=0;j<n;j++){
      if(j%2 == 0){
        int k;
        for(k=0;k<v[j]-1;k++){
          s += (char)(*(s.end()-1) + 1);
        }
        if(j<=n-2){
          if(v[j]>v[j+1]){
            s += (char)(*(s.end()-1) + 1);
          }else{
            s += (char)('A' + v[j+1]);
          }
        }else{
          s += (char)(*(s.end()-1) + 1);
        }
      }else{
        string temp = "";
        for(int k=0;k<v[j];k++){
          temp += 'A'+k;
        }
        reverse(temp.begin(), temp.end());
        s += temp;
      }
    }
    cout<<s<<endl;
  }
  return 0;
}