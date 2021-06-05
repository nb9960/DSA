// koi bhi edge same set m na ho mtlb dono endpoint separate sets m ho
// algo: agar saari vertices ko 2 colors m rang sakte ho such that 2 vertices joining an edge has diff colors then bipartite

#include <bits/stdc++.h>
using namespace std;
#define V 4

bool isBipartiteUtil(int G[][V], int src, int color[V]){
  color[src] = 1; // assign 1st color to src
  queue<int> q;
  q.push(src);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    if(G[u][u] == 1) return false;  // return false agar jisko value assign karne wale the usme pehle hi ek value hai kyuki iska mtlb self loop
    for(int v=0;v<V;v++){ // saari non colored adj vertices ke paas jao
      if(G[u][v] && color[v] == -1){
        color[v] = 1 - color[u]; // assign alternate color to this adj v of u
        q.push(v);
      }
      else if(G[u][v] && color[u] == color[v])
        return false; // edge hai u v mei aur dono vertices ka color same hai
    }
  }
  return true;
}

bool isBipartite(int G[][V]){
  int color[V]; // color[i] == ith vertex ko kaunsa color diya -1 (No color) 1 (1st color) ya 0 (2nd color)
  for(int i=0;i<V;i++)
    color[i] = -1;
  // to handle disconnected graph
  for(int i=0;i<V;i++)
    if(color[i] == -1)
      if(isBipartiteUtil(G,i,color) == false)
        return false;
  return true;
}

bool colorGraph(int G[][V], int color[], int pos, int c){
  if(color[pos] != -1 && color[pos] != c) // opposite rang m ranga hua hai
    return false;
  color[pos] = c;
  bool ans = true;
  for(int i=0;i<V;i++){
    if(G[pos][i]){
      if(color[i] == -1)
        ans &= colorGraph(G, color, i, 1-c);
      if(color[i] != -1 && color[i] != 1-c)
        return false;
    }
    if(!ans) return false;
  }
  return true;
}

bool isBipartiteDFS(int G[][V]){
  int color[V]; // color[i] == ith vertex ko kaunsa color diya -1 (No color) 1 (1st color) ya 0 (2nd color)
  for(int i=0;i<V;i++)
    color[i] = -1;
  int pos = 0;
  return colorGraph(G, color, pos, 1); // vertex 0 with color 1
}

int main(){
  int G[][V] = {{0,1,0,1},
                {1,0,1,0},
                {0,1,0,1},
                {1,0,1,0}};
  isBipartite(G) ? cout<<"Yes" : cout<<"No";
  isBipartiteDFS(G) ? cout<<"Yes" : cout<<"No";
  return 0;
}
