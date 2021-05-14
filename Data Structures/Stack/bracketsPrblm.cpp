// Author:Nishtha

#include <bits/stdc++.h> 
using namespace std; 
  
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pl; 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<pii> vpii; 

bool validBrackets(string s){
  stack<char>st;
  fi(i,0,s.size())
  {
    if(s[i]=='(' || s[i] =='{' || s[i]=='[')
    {
      st.push(s[i]);
    }
    else
    {
      if(st.empty())
      {
        return false;
        break;
      }
      char top=st.top();
      st.pop();
      if(s[i] ==')'){
        if(top == '{' || top == '[') return false;
        break;
      }
      if(s[i] =='}'){
        if(top == '(' || top == '[') return false;
        break;
      }
      if(s[i] ==']'){
        if(top == '(' || top == '{') return false;
        break;
      }
    }
  }
  return st.empty();
}

// Drive Code 
int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  // Test Cases 
  ll t = 1; 
  // cin >> t;
  // cout<<"hello"<<endl;
  while (t--) { 
    string s;
    cin>>s;
    if(validBrackets(s)){
      cout<<"bdhiya"<<endl;
    }else{
      cout<<"bekar"<<endl;
    }
  } 

  return 0; 
} 
