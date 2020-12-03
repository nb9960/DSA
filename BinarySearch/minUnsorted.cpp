// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long


/* 
left se right chalo aur pehle aise element ka index s btao such that a[s]>a[s+1]
next, right se left chalo pehla aise element k index e ko pkdo such that a[e]<a[e-1]
ab check krna h ki iss range k elements ko sort krne se sab sort ho bhi rhe ya nahi
toh a[s to e] m min aur max value btao
pehla aisa element dhundho a[0 to s-1] m jo min se bada ho agar mile toh s= uska index
last element dhundo a[e+1 to n-1] , jo max se chhota ho aur e ko uss element ka index rakh lo
*/

void printUnsorted(int a[], int n){
  int start=0,end=n-1,i,max,min;
  for(start=0;start<n-1;start++){
    if(a[start]>a[start+1])
      break;
  }
  if(start==n-1){
    cout<<"Array is already sorted";
    return;
  }
  for(end=n-1;end>0;end--){
    if(a[end]<a[end-1]){
      break;
    }
  }
  max=a[start]; min=a[start];
  for(i=start+1;i<=end;i++){
    if(a[i]>max)
      max=a[i];
    if(a[i]<min)
      min=a[i];
  }
  for(i=0;i<start;i++){
    if(a[i]>min){
      start=i;
      break;
    }
  }
  for(i=n-1;i>=end+1;i++){
    if(a[i]<max){
      end=i;
      break;
    }
  }
  cout<<"The unsorted subarray which makes the given array sorted lies b/w the indices "<<start<<" and "<<end<<endl;
}

int main() 
{  
  int n;
  cin>>n;
  int a[n];
  fi(i,0,n){
    cin>>a[i];
  }
  printUnsorted(a,n);
  getchar();
  return 0; 
} 
