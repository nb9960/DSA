// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 

int myAtoi(string s){
  int sign =1, base=0, i=0;
  while(s[i]==' '){
    i++;
  }
  if(s[i]=='-' || s[i]=='+'){
    sign = 1-2*(s[i++]=='-');
  }
  while(s[i]>='0' && s[i]<='9'){
    if(base>INT_MAX/10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
      if(sign==1)
        return INT_MAX;
      else return INT_MIN;
    }
    base = 10*base + (s[i++]-'0');
  }
  return base*sign;
}

int main() 
{  
  string s;
  cin>>s;
  int val = myAtoi(s);
  cout<<val;
  return 0; 
} 
