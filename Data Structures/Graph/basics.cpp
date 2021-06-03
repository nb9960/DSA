#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v; // no. of vertices
    list<int> *adj;
    void DFSUtil(int ind, bool visited[]);
    bool isCyclicUtil(int v, bool visited[], bool *rs);
  public:
    Graph(int v);
    void addEdge(int v, int w);
    bool isReachable(int s, int d);
    bool isCyclic();
    void DFS();
    void BFS(int s);
};

Graph::Graph(int v){
  this->v = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w); // Add w to v's list
}

// A BFS based function to check whether d is reachable from s
bool Graph::isReachable(int s, int d){
  if(s==d) return true;
  bool *visited = new bool[v];
  for(int i=0;i<v;i++) visited[i] = false;

  list<int> queue;

  visited[s] = true;
  queue.push_back(s);
  list<int>::iterator i;

  while(!queue.empty()){
    s = queue.front();
    queue.pop_front();
    for(i=adj[s].begin();i!=adj[s].end();i++){
      if(*i == d)
        return true;
      if(!visited[*i]){
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  } 
  return false;
}

void Graph::BFS(int s){
  bool *visited = new bool[v];
  for(int i=0;i<v;i++)
    visited[i] = false;

  list<int> queue;
  visited[s] = true;
  queue.push_back(s);

  list<int>::iterator i;

  while(!queue.empty()){
    s = queue.front();
    cout<<s<<" ";
    queue.pop_front();

    // get all adjacent vertices of the dequeued vertex s. agar nahi visit hui h abhi tk to visit wala true kro aur enque kro
    for(i=adj[s].begin();i!=adj[s].end();i++){
      if(!visited[*i]){
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack){
  if(!visited[v]){
    visited[v] = true;
    recStack[v] = true;

    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end();i++){
      if(!visited[*i] && isCyclicUtil(*i, visited, recStack))
        return true;
      else if(recStack[*i])
        return true;
    }
  }

  recStack[v] = false;
  return false;
}

bool Graph::isCyclic(){
  bool *visited = new bool[v]; // visited or not
  bool *recStack = new bool[v]; // part of rec tree or not
  for(int i=0;i<v;i++){
    visited[i] = false;
    recStack[i] = false;
  }

  for(int i=0;i<v;i++)
    if(isCyclicUtil(i, visited, recStack));
      return true;
  
  return false;
}

int main(){
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Breadth First Traversal \n";
  g.BFS(2);
  cout<<"\n";

  cout << "Following is Depth First Traversal \n";
  g.DFS();
  cout<<"\n";

  if(g.isCyclic()) cout<<"Graph contains cycle \n";
  else cout<<"Graph doesn't contain cycle\n";

  return 0;
}