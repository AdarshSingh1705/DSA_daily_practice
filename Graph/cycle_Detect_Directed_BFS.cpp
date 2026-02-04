#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;


class Graph{
  int V;
  vector<vector<int>> adj;

public:

  Graph(int vertices){
    V = vertices;
    adj.resize(V);
  }

  void addEdges(int u, int v, bool visited = false){

    adj[u].push_back(v);
    if(!visited){
      adj[v].push_back(u);
    }
  }
  
  
};


int main(){

  Graph g(6);

  g.addEdges(5, 2, true);
  g.addEdges(5, 0, true);
  g.addEdges(4, 0, true);
  g.addEdges(4, 1, true);
  g.addEdges(2, 3, true);
  g.addEdges(3, 1, true);


  return 0;
}
