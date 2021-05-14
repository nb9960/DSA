#include <bits/stdc++.h>
using namespace std;
#define HASH_SIZE 128

int main(){
  int r = 5, c = 6; 
  int size = r*c; 
  int *A = new int[size]; 

  for(int i = 0; i < size; i++) 
      A[i] = i+1;

  // for(int i=0;i<r;i++){
  //   for(int j=0;j<c;j++){
  //     cout<<*(A+i*c+j);
  //   }
  // }

  int t,next, cycleBegin, i=1;
  bitset<HASH_SIZE> b;
  b.reset();
  b[0] = 1; b[size-1] =1;

  while(i<size-1){
    cycleBegin = i; t=A[i];
    do{
      next = (i*r) % (size-1);
      swap(A[next], t);
      b[i]=1; i=next;
    }while(i!=cycleBegin);
    for(i=1;i<size-1 && b[i];i++);
  }

  for(int i=0;i<c;i++){
    for(int j=0;j<r;j++){
      cout<<*(A+ i*r +j)<<" ";
    }
    cout<<"\n";
  } 
  return 0;
}