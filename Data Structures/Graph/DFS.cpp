#include <bits/stdc++.h>
using namespace std;
 
class Graph {
    // A function used by DFS
  void DFSUtil(int v);

public:
  map<int, bool> visited;
  map<int, list<int>> adj;
  // function to add an edge to graph
  void addEdge(int v, int w);

  // prints DFS traversal of the complete graph
  void DFS();
};
 
void Graph::addEdge(int v, int w){
  adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v){
  // Mark the current node as visited and print it
  visited[v] = true;
  cout << v << " ";

  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
          DFSUtil(*i);
}

void Graph::DFS(){
  for(auto i:adj)
    if(visited[i.first] == false)
      DFSUtil(i.first);
}

int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal \n";
    g.DFS();
 
    return 0;
}