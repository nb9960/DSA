#include <bits/stdc++.h>
using namespace std;

// This represents linear ordering of a graph
// topological sorting == harr edge(u,v) ke liye jo order print karao usme u pehle aana chahiye v se
// Algorithm is similar to DFS bs print na kara ke stack m add karo aur jab sab add ho jae tb print karao

class Graph{
  int V;
  list<int>* adj;
  void topoSortUtil(int v, bool visited[], stack<int>& s);
public:
  Graph(int V);
  void addEdge(int v, int w);
  void topologicalSort();
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
}

void Graph::topoSortUtil(int v, bool visited[], stack<int>& s){
  // Mark the current node as visited and print it
  visited[v] = true;

  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
          topoSortUtil(*i, visited, s);

  s.push(v);
}

void Graph::topologicalSort(){
  stack<int> s;
  bool* visited = new bool[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  for(int i=0;i<V;i++)
    if(!visited[i])
      topoSortUtil(i, visited, s);

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
}

int main(){
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  cout << "Following is a Topological Sort of the given "
          "graph \n";

  // Function Call
  g.topologicalSort();
  return 0;
}