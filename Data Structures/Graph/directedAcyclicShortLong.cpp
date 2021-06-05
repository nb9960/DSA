/* Pehle topological order nikalo aur fir ek ek krke uske saare vertices ko process karo arthat update 
distances of its adjacent using distance of current vertex.*/

#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define NINF INT_MIN

class AdjListNode{
  int v;
  int weight;
public:
  AdjListNode(int _v, int _w) { v = _v;  weight = _w;}
  int getV(){return v;}
  int getWeight() { return weight; }
};

class Graph{
  int V;
  list<AdjListNode> *adj;
  void topoSortUtil(int v, bool visited[], stack<int> &s);
public:
  Graph(int V);
  void addEdge(int u, int v, int weight);
  void shortestPath(int s);
  void longestPath(int s);
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight){
  AdjListNode node(v, weight);
  adj[u].push_back(node);
}

void Graph::topoSortUtil(int v, bool visited[], stack<int> &s){
  visited[v] = true;

  list<AdjListNode>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i){
    AdjListNode node = *i;
    if (!visited[node.getV()])
      topoSortUtil(node.getV(), visited, s);
  }
  s.push(v);
}

void Graph::shortestPath(int s){
  stack<int> S;
  int dist[V];
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)
    if(!visited[i])
      topoSortUtil(i, visited, S);
  for(int i=0;i<V;i++)
    dist[i] = INF;
  dist[s] = 0;
  while(!S.empty()){
    int u=S.top();
    S.pop();
    list<AdjListNode>::iterator i;
    if(dist[u] != INF){
      for(i=adj[u].begin(); i!=adj[u].end();i++)
        if(dist[i->getV()] > dist[u] + i->getWeight())
          dist[i->getV()] = dist[u] + i->getWeight();
    }
  }
  for(int i=0;i<V;i++)
    (dist[i] == INF) ? cout<<"INF " : cout<<dist[i]<<" ";
}

void Graph::longestPath(int s){
  stack<int> S;
  int dist[V];
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)
    visited[i] = false;
  for(int i=0;i<V;i++)
    if(!visited[i])
      topoSortUtil(i, visited, S);
  for(int i=0;i<V;i++)
    dist[i] = NINF;
  dist[s] = 0;
  while(!S.empty()){
    int u=S.top();
    S.pop();
    list<AdjListNode>::iterator i;
    if(dist[u] != NINF){
      for(i=adj[u].begin(); i!=adj[u].end();i++)
        if(dist[i->getV()] < dist[u] + i->getWeight())
          dist[i->getV()] = dist[u] + i->getWeight();
    }
  }
  for(int i=0;i<V;i++)
    (dist[i] == NINF) ? cout<<"INF " : cout<<dist[i]<<" ";
}

int main(){
  Graph g(6);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 3, 6);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(2, 3, 7);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);

  int s = 1;
  // cout << "Following are shortest distances from source " << s <<": \n";
  // g.shortestPath(s);

  cout << "Following are longest distances from source " << s <<": \n";
  g.longestPath(s);
  return 0;
}