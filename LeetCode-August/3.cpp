#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define fi(i, a, n) for (ll i = a; i < n; i++)
#define fd(i, a, n) for (ll i = a; i >= n; i--)
#define pb push_back
#define fv(i, a) for (auto i : a)
#define vi vector<int>

int main()
{
  string s;
  cin >> s;
  string s1;
  bool b=true;
  for (int i = 0; i < s.length(); i++)
  {
    if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 92) || (s[i] >= 97 && s[i] <= 122))
    {
      if (s[i] >= 65 && s[i] <= 92)
      {

        s[i]=s[i]+32;
      }
     
        s1.push_back(s[i]);
   
    }
  }
  for (int i = 0; i < s1.length(); i++)
  {
    if (s1[i] != s1[s1.length() - i - 1])
    {
      b=false;
    }
  }
  cout<<b<<endl;

  return 0;
}