#include <bits/stdc++.h>
using namespace std;

struct Box{
  int h,w,d;
};

int compare (const void *a, const void * b){
  return ( (*(Box *)b).d * (*(Box *)b).w ) -
          ( (*(Box *)a).d * (*(Box *)a).w );
}

int main(){
  Box a[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
  int n = sizeof(a)/sizeof(a[0]);

  Box rot[3*n];
  int ind = 0;
  for(int i=0;i<n;i++){
    // Copy the original box
    rot[ind].h = a[i].h;
    rot[ind].d = max(a[i].d, a[i].w);
    rot[ind].w = min(a[i].d, a[i].w);
    ind++;

    // First rotation of box
    rot[ind].h = a[i].w;
    rot[ind].d = max(a[i].h, a[i].d);
    rot[ind].w = min(a[i].h, a[i].d);
    ind++;

    // Second rotation of box
    rot[ind].h = a[i].d;
    rot[ind].d = max(a[i].h, a[i].w);
    rot[ind].w = min(a[i].h, a[i].w);
    ind++;
  }
  n = 3*n;
  qsort(rot, n, sizeof(rot[0]), compare);

  // msh[i] --> Max possible stack ht with box i on top
  int msh[n];
  int maxm = -1;
  for(int i=0;i<n;i++) msh[i] = rot[i].h;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(rot[i].w < rot[j].w && rot[i].d < rot[j].d && msh[i] < msh[j] + rot[i].h){
        msh[i] = msh[j] + rot[i].h;
      }
    }
    maxm = max(maxm, msh[i]);
  }
  cout<<"Maximum possible height of stack: "<<maxm<<endl;
  return 0;
}