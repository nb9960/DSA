#include <bits/stdc++.h>
using namespace std;

// ABCD, ACBD, ACDB are interleaved of AB & CD

int main(){
  string a, b, c;
  /* XXY XXZ XXZXXXY
    XY WZ WZXY
    XY X XXY
    YX X XXY
    XXY XXZ XXXXZY */

  int m = a.size(), n = b.size();
  // interl[i][j] = true if interl[0....i+j-1] is interleaving of
  // a[0....i-1] and b[0....j-1]
  bool interl[m+1][n+1];
  memset(interl, false, sizeof(interl));

  if((m+n) != c.size()) return false;

  // process all char of a and b
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      if(i==0 && j==0) // 2 empty strings arthaat true
        interl[i][j] = true;

      // a is empty
      else if(i==0){
        if(b[j-1] == c[j-1])
          interl[i][j] = interl[i][j-1];
      }

      // b is empty
      else if(j==0){
        if(a[i-1] == c[i-1])
          interl[i][j] = interl[i-1][j];
      }

      // current char of c matches with curr of a but doesn't matches with curr of b
      else if(a[i-1] == c[i+j-1] && b[j-1] != c[i+j-1])
        interl[i][j] = interl[i-1][j];

      // current char of c matches with curr of b but doesn't matches with curr of b
      else if(a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1])
        interl[i][j] = interl[i][j-1];

      // curr char of c matches with that of both a and b
      else if(a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1])
        interl[i][j] = (interl[i][j-1] || interl[i-1][j]);
    }
  }

  (interl[m][n]) ? cout<<"Is interleaved"<<endl : cout<<"Is not interleaved"<<endl;
  return 0;
}