#include <bits/stdc++.h>
using namespace std;

/*
- ye DP ke niyamo ke anusar chalta h: saare solutions try karo aur best pick kro
- ye bolta h ki: saari edges V-1 times pick kro aur relax krao
- iska peeche ka idea ye hai ki agar koi shortest path saari edges include kr rha then at most V-1 edges hongi aise path m
- relaxation: between the edge u,v if (d[u] + cost(u,v) < d[v]) then change d[v] kyuki mtlb usse shortest path aur hai
- in case of complete graph (mtlb harr 2 node ke beech edge mtlb edges n(n-1)/2 hongi) : O(n3) else avg = O(n2)
- ye fail ho jaata h agar -ve weight cycle hai
*/

class Edge{
  public:
    int src, dest, wt;
};

class Graph{
public:
  int V, E;
  Edge* edge;
};

Graph* createGraph(int V, int E){
  Graph* graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

void BellmanFord(Graph *graph, int src){
  int V = graph->V, E = graph->E;
  int dist[V];

  // initially sab INF bs src wla 0 because src ka khud ka dist 0
  for(int i=0;i<V;i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  // saare edges relax kro V-1 times bcz A simple shortest
  // path from src to any other vertex can have at-most |V| - 1 edges 
  for(int i=1;i<=V-1;i++){
    for(int j=0;j<E;j++){
      int u=graph->edge[j].src;
      int v = graph->edge[j].dest;
      int wt = graph->edge[j].wt;
      if(dist[u]!=INT_MAX && dist[u] + wt < dist[v])
        dist[v] = dist[u] + wt; 
    }
  }

  // dekho kahi -ve wt cycle kyuki agar hai toh abhi bhi relaxation hoga kyuki iss case m ye fail kr jaati h
  for(int i=0;i<E;i++){
    int u=graph->edge[i].src;
    int v = graph->edge[i].dest;
    int wt = graph->edge[i].wt;
    if(dist[u]!=INT_MAX && dist[u] + wt < dist[v]){
      cout<<"Graph contains a -ve cycle"<<endl;
      return;
    }
  }

  // agar -ve cycle nahi to array print karo
  cout<<"Vertex \t\t Distance from source"<<endl;
  for(int i=0;i<V;i++)
    cout<<i<<" \t\t "<<dist[i]<<endl;
  return;
}

int main(){
  int V = 5; // Number of vertices in graph
  int E = 8; // Number of edges in graph
  struct Graph* graph = createGraph(V, E);

  // add edge 0-1 (or A-B in above figure)
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[0].wt = -1;

  // add edge 0-2 (or A-C in above figure)
  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[1].wt = 4;

  // add edge 1-2 (or B-C in above figure)
  graph->edge[2].src = 1;
  graph->edge[2].dest = 2;
  graph->edge[2].wt = 3;

  // add edge 1-3 (or B-D in above figure)
  graph->edge[3].src = 1;
  graph->edge[3].dest = 3;
  graph->edge[3].wt = 2;

  // add edge 1-4 (or A-E in above figure)
  graph->edge[4].src = 1;
  graph->edge[4].dest = 4;
  graph->edge[4].wt = 2;

  // add edge 3-2 (or D-C in above figure)
  graph->edge[5].src = 3;
  graph->edge[5].dest = 2;
  graph->edge[5].wt = 5;

  // add edge 3-1 (or D-B in above figure)
  graph->edge[6].src = 3;
  graph->edge[6].dest = 1;
  graph->edge[6].wt = 1;

  // add edge 4-3 (or E-D in above figure)
  graph->edge[7].src = 4;
  graph->edge[7].dest = 3;
  graph->edge[7].wt = -3;

  BellmanFord(graph, 0); 
  return 0;
}