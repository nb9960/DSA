#include <bits/stdc++.h>
using namespace std;

class Edge{
  public:
    int src, dest;
};

class subset{
public:
  int parent,rank;
};

class Graph{
public:
  int V, E;
  Edge *edge;
};

Graph* createGraph(int V, int E){
  Graph* graph = new Graph();
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[graph->E * sizeof(Edge)];
  return graph;
}

int findOp(subset subsets[], int i){
  if(subsets[i].parent != i)
    subsets[i].parent = findOp(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void UnionOp(subset subsets[],int x, int y){
  // small rank wale ko high rank wale ka child bnao
  if(subsets[x].rank < subsets[y].rank)
    subsets[x].parent = y;
  else if(subsets[x].rank > subsets[y].rank)
    subsets[y].parent = x;
  // if ranks same toh ek ko root bnao aur uski rank bdhao
  else{
    subsets[y].parent = x;
    subsets[x].rank++; 
  } 
}

bool isCycleOptimized(Graph* graph){
  int V = graph->V, E = graph->E;
  subset* subsets = new subset[V * sizeof(subset)];
  for(int v=0;v<V;v++){
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }
  for(int e=0;e<E;e++){
    int x = findOp(subsets, graph->edge[e].src);
    int y = findOp(subsets, graph->edge[e].dest);
    if(x==y) return true;
    UnionOp(subsets, x, y);
  }
  return false;
}

int find(int parent[], int i){
  if(parent[i] == -1)
    return i;
  return find(parent, parent[i]);
}

void Union(int parent[],int x, int y){
  parent[x] = y;
}

bool isCycle(Graph* graph){
  int *parent = new int[graph->V * sizeof(int)];
  memset(parent, -1,sizeof(int) * graph->V);

  // saari edges ke dono vertices k subsets dekho agra == hai to cycle bnn rahi h warna union lo
  for(int i=0;i<graph->E;i++){
    int x= find(parent, graph->edge[i].src);
    int y = find(parent, graph->edge[i].dest);
    if(x==y) return true;
    Union(parent, x,y);    
  }
  return false;
}

int main(){
  int V = 3, E = 3;
  Graph* graph = createGraph(V, E);

  // add edge 0-1
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;

  // add edge 1-2
  graph->edge[1].src = 1;
  graph->edge[1].dest = 2;

  // add edge 0-2
  graph->edge[2].src = 0;
  graph->edge[2].dest = 2;

  if (isCycle(graph))
      cout << "graph contains cycle";
  else
      cout << "graph doesn't contain cycle";

  if (isCycleOptimized(graph))
      cout << "graph contains cycle";
  else
      cout << "graph doesn't contain cycle";
  return 0;
}