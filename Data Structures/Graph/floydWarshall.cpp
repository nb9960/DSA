#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999

void floydWarshall(int graph[V][V]){
  int dist[V][V]; // output matrix where dist[i][j] = shortest dist bw i and j; initially set to be same as graph matrix
  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
      dist[i][j] = graph[i][j]; // this doesn't consider any intermediate vertex

  for(int k=0;k<V;k++){
    // pick all vertices as src one by one
    for(int i=0;i<V;i++){
      // pick all vertices as dest for above src
      for(int j=0;j<V;j++){
        // if k is on shortest path from i to j then update dist[i][j]
        if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > (dist[i][k] + dist[k][j]))
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  cout<<"following shows the shortest distance between every pair of vertices \n";
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      if(dist[i][j]==INF) cout<<"INF\t\t";
      else cout<<dist[i][j]<<"\t\t";
    }
  }
}

int main(){
  int graph[V][V] = { { 0, 5, INF, 10 },
                      { INF, 0, 3, INF },
                      { INF, INF, 0, 1 },
                      { INF, INF, INF, 0 } };
  floydWarshall(graph);
  return 0;
}