#include <iostream>
#define V 8
#define I 32767

using namespace std;

/*
  - Prism bolta hai ki minimum && nearest (arthat last 2 ends se connected) wali edge pakdo
  - kruskal's bolta hai ki minimum edge pakdo but make sure ki vo loop nhi bana rahi h arthat 
  agar loop bana rahi ho vo edge toh skip kar do
  - Kruskal's cyclic component k liye minimum spanning tree find karke de skta h prism nhi
*/

void PrimsMST(int cost[V][V], int n){ 
  int u,v, min = I, track[V] = {0}, T[2][V-1] = {0};
  // 1. find min cost edge
  for (int i=1; i<V; i++){
    track[i] = I;  // Initialize track array with INFINITY
    for (int j {i}; j<V; j++){
        if (cost[i][j] < min){
            min = cost[i][j];
            u = i;
            v = j;
        }
    }
  }

  T[0][0]=u; T[1][0] = v; track[u] = track[v] = 0;

  // track array fill karo to find near wala min cost edge
  for(int i=1;i<V;i++){
    if(track[i] != 0){
      if(cost[i][u] < cost[i][v])
        track[i] = u;
      else track[i] = v;
    }
  }

  //  Repeat to find other edges similarly i.e vo nearest vertex pick kro jiski edge minimum ho
  for(int i=1;i<n-1;i++){
    int k;
    min=I;
    for(int j=1;j<V;j++){
      if(track[j] != 0 && cost[j][track[j]] < min){
        k=j;
        min=cost[j][track[j]];
      }
    }
    T[0][i] = k; T[1][i] = track[k];
    track[k] = 0;

    // Update track array to track min cost edges
    for(int j=1;j<V;j++){
      if(track[j] != 0 && cost[j][k]<cost[j][track[j]])
        track[j] = k;
    }
  }

    // now find total cost of T wali edges alongwith printing edges
    int sum =0;
    cout<<"\n Minimum spanning tree edges \n"<<endl;
    for(int i=0;i<V-2;i++){
      int c=cost[T[0][i]][T[1][i]];
      cout<<"["<<T[0][i]<<"]---["<<T[1][i]<<"] cost: "<<c<<endl;
      sum+=c;
    }
    cout<<"\n Total cost of MST: "<<sum<<endl;
}

int main() {
    int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
 
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
 
    PrimsMST(cost, n);
 
    return 0;
}