// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

/*
Calculate m1 & m2 medians of 2 arrays
if m1==m2 return m1
if m1>m2 then median in 2 mese kisi m milega
  (i) a1[0 to |n/2|]
  (ii) a2[|n/2| to n-1]
if m2>m1 then below 2 m se kahi milega
  (i) a1[|n/2| to n-1]
  (ii) a2[0 to |n/2|]
Repeat jab tk size 2 na bnn jaye
2 hi element bachhe to median=(max(a1[0],a2[0]) +min(a1[1],a2[1]))/2
*/

int median(int a[], int n){
  if(n%2 == 0)
    return (a[n/2]+a[n/2-1])/2;
  return a[n/2];
}

int getMedian(int a1[], int a2[], int n){
  if(n==0)
    return -1;
  if(n==1)
    return (a1[0]+a2[0])/2;
  if(n==2)
    return (max(a1[0],a2[0]) +min(a1[1],a2[1]))/2;
  int m1=median(a1,n),m2=median(a2,n);
  if(m1==m2)
    return m1;
  if(m1<m2){
    if(n%2==0)
      return getMedian(a1+n/2-1,a2,n-n/2+1);
    return getMedian(a1+n/2,a2,n-n/2);
  }
  if(n%2==0)
    return getMedian(a2+n/2-1,a1,n-n/2+1);
  return getMedian(a2+n/2,a1,n-n/2);
}

int main() 
{  
  int n;
  cin>>n;
  int a1[n],a2[n];
  fi(i,0,n)
  cin>>a1[i];
  fi(i,0,n)
  cin>>a2[i];
  cout<<getMedian(a1,a2,n);
  return 0; 
} 
