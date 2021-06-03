/*
- find minimum edge
- check kro vo set m hai ya nhi mtlb unka koi parent same hai ya nhi
    - parent same hai matlab cycle form karega else add karo usse aur table update karo
-  check kro included hai ya nhi aur update kro included wala table
- include the edge in final table
*/

#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
  // V --> no. of vertices, E --> no. of edges
  int V, E;
  Edge *edge;
};

Graph* createGraph(int V, int E){
  Graph* graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

// structure to represent subset for union-find
class subset{
public:
  int parent;
  int rank;
};

int mycmp(const void* a, const void* b){
  Edge* a1 = (Edge*)a;
  Edge* b1 = (Edge*)b;
  return a1->weight > b1->weight;
}

int find(subset subsets[], int i){
  if(subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);
   
  // attach smaller rank tree under tree of high rank tree
  if(subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if(subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
  else{
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

void KruskalMST(Graph* graph){
  int V = graph->V;
  Edge result[V]; // for storing resultant mst
  int e=0; // used for result[] 
  int i=0; // used for sorted edges

  // Sort all edges in inc order of wt.
  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), mycmp);

  subset* subsets = new subset[(V*sizeof(subset))];

  for(int v=0;v<V;v++){
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  while(e<V-1 && i<graph->E){
    // pick smallest edge and inc index of next iteration
    Edge next_edge = graph->edge[i++];
    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);
    //manjhe cycle nahi banaenge arthat result m include kro aur index increament kro of result for next edge
    if(x != y){ 
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }

  // print the contents of result[] to display the built MST
  cout << "Following are the edges in the constructed MST\n";
  int minimumCost = 0;
  for (i = 0; i < e; ++i){
      cout << result[i].src << " -- " << result[i].dest
            << " == " << result[i].weight << endl;
      minimumCost = minimumCost + result[i].weight;
  }
  // return;
  cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}

int main(){
  int V=4, E=5;
  Graph *graph = createGraph(V, E);
    // add edge 0-1
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[0].weight = 10;

  // add edge 0-2
  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[1].weight = 6;

  // add edge 0-3
  graph->edge[2].src = 0;
  graph->edge[2].dest = 3;
  graph->edge[2].weight = 5;

  // add edge 1-3
  graph->edge[3].src = 1;
  graph->edge[3].dest = 3;
  graph->edge[3].weight = 15;

  // add edge 2-3
  graph->edge[4].src = 2;
  graph->edge[4].dest = 3;
  graph->edge[4].weight = 4;

  
  // Function call
  KruskalMST(graph);
  return 0;
}