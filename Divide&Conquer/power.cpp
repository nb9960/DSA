// nb_9960
#include <bits/stdc++.h> 
using namespace std; 

float power(float x,int y){
  float tmp;
  if(y==0)
    return 1;
  tmp = power(x,y/2);
  if(y%2==0)
    return tmp*tmp;
  else{
    if(y>0)
      return x*tmp*tmp;
    else return (tmp*tmp)/x;
  }
}

int main() 
{  
  float x;
  int n;
  cin>>x>>n;
  cout<<power(x,n)<<endl;
  return 0; 
} 
