#include <bits/stdc++.h>
using namespace std;
#define V 9

/*
Ye bola ki jisko visit kr chuke ho usko reconsider mt kro relaxation ke liye
tbhi -ves ke liye fail ho gya
kyuki anusar pehle minm lo joki visit nhi hua hai aur fir aage ki saari vertices relax krao 
*/

// min dist vertex jo inc nahi uska index
int minDist(int dist[], bool inc[]){
  int min = INT_MAX, min_ind;
  for(int v=0;v<V;v++)
    if(!inc[v] && dist[v] <= min)
      min = dist[v], min_ind = v;
  return min_ind;
}

void dijkstra(int graph[V][V], int src){
  int dist[V]; // dist[i]-->the shortest distance from src to i
  bool inc[V]; // inc[i] = true if vertex i is included in path tree or shortest distt from src to i is finalized

  // initialize all dist as INF and inc[] as false
  for(int i=0;i<V;i++)
    dist[i] = INT_MAX, inc[i] = false;
  dist[src] = 0; // dist of src vertex from itself is 0

  // find shortest path from all vertices
  for(int count =0;count<V-1;count++){
    int u = minDist(dist, inc); // min dist vertex uthao jo abhi tk pick na hui ho
    inc[u] = true; // picked vertex ko inc kr do
    // picked vertex ki aas paas vali vertices ka dist update kro
    for(int v=0;v<V;v++)
      if(!inc[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v]; 
  }

  printf("Vertex \t\t Distance from Source\n");
  for (int i = 0; i < V; i++)
    cout<<i<<"\t"<<dist[i]<<endl;
}


int main(){
  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

  dijkstra(graph, 0);
  return 0;
}

/*
- calculates shortest distance, but doesn’t calculate the path information. 
  We can create a parent array, update the parent array when distance is updated (like prim’s implementation) 
  and use it show the shortest path from source to different vertices.
- Its for undirected graph, same dijkstra function can be used for directed graphs also.
- finds shortest distances from source to all vertices. If we are interested only in shortest distance 
  from the source to a single target, we can break the for the loop when the picked minimum distance vertex 
  is equal to target (Step 3.a of the algorithm).
- Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, 
  it can be reduced to O(E log V) with the help of binary heap.
- Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles
*/
