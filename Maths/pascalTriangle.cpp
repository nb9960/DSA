/*
Idea:We know that ith entry in a line number 'line' is Binomial 
Coefficient C(line, i) and all lines start with value 1. 
The idea is to calculate C(line, i) using C(line, i-1). 
It can be calculated in O(1) time using the following.

C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time
*/

// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i <= n; i++) 

void printPascal(int n){
  fi(line,1,n){
    int C=1;
    fi(i,1,line){
      cout<<C<<" ";
      C = C*(line-i)/i;
    }
    cout<<"\n";
  }
}

int main() 
{  
  int n;
  cin>>n;
  printPascal(n); 
  return 0; 
} 
