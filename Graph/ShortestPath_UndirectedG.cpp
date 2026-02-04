
// Shortest Path for undirected and unweighted in a Graph

#include<iostream>
#include<vector>
#include<algorithm> // if reversing then use it
#include<queue>
using namespace std;

class Graph{
  int V;
  vector<vector<int>> adj;

public:

  Graph(int vertices){
    V = vertices;
    adj.resize(V);
  }

  void addEdges(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> shortPath(int src, int des){
    vector<bool> visited(V, false);
    vector<int> parent(V);
    queue<int> q;

    parent[src] = -1;
    visited[src] = true;
    q.push(src);

    while(!q.empty()){
      int front = q.front();
      q.pop();

      for(auto neigh : adj[front]){
        if(!visited[neigh]){
          visited[neigh] = true;
          parent[neigh] = front;
          q.push(neigh);
        }
      }
    }

    vector<int> ans;
    int currentNode = des;
    ans.push_back(currentNode);

    while(currentNode != src){
      currentNode = parent[currentNode];
      ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};


int main(){

  Graph g(9);

  g.addEdges(1, 2);
  g.addEdges(1, 3);
  g.addEdges(1, 4);
  g.addEdges(2, 5);
  g.addEdges(3, 5);
  g.addEdges(4, 6);
  g.addEdges(5, 8);
  g.addEdges(6, 7);
  g.addEdges(7, 8);
  g.addEdges(3, 8);

  vector<int>ans = g.shortPath(1, 8);

  for(int i=0; i < ans.size(); i++){
    cout << ans[i] << "-> ";
  }

  return 0;
}