
// Shortest Path in Directed Acyclic Graph

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<limits>
#include<stack>
using namespace std;

class Graph{
  int V;
  unordered_map<int, list<pair<int, int> > > adj;

  public:

  Graph(int vertices){
    V = vertices;
  }

  void addEdges(int u, int v, int w){
    adj[u].push_back({v, w});
  }

  void dfs(int node, unordered_map<int, bool>& visited, stack<int>& st){
    visited[node] = true;
    
    for(auto neigh : adj[node]){
      if(!visited[neigh.first]){
        dfs(neigh.first, visited, st);
      }
    }
    st.push(node);
  }



  void getShortDist(int src, vector<int>& dist, stack<int>& st){
    
    dist[src] = 0;

    while(!st.empty()){
      int top = st.top();
      st.pop();

      if(dist[top] != INT_MAX){
        for(auto i : adj[top]){
          if(dist[top] + i.second < dist[i.first]){
            dist[i.first] = dist[top] + i.second;
          }
        }
      }
    }
  }

  vector<int> shortPath(int src) {

    unordered_map<int, bool> visited;
    stack<int> st;
    vector<int> dist(V, INT_MAX);

    for(int i=0; i < V; i++){
      if(!visited[i]){
        dfs(i, visited, st);
      }
    }

    getShortDist(src, dist, st);
    return dist;
  }
};


int main(){

  Graph g(6);

  g.addEdges(0, 1, 5);
  g.addEdges(0, 2, 3);
  g.addEdges(1, 2, 2);
  g.addEdges(1, 3, 6);
  g.addEdges(2, 3, 7);
  g.addEdges(2, 4, 4);
  g.addEdges(2, 5, 2);
  g.addEdges(3, 4, -1);
  g.addEdges(4, 5, -2);


  vector<int>ans = g.shortPath(1);

    for(int i=0; i < ans.size(); i++){
      if(ans[i] == INT_MAX) cout << " INF " ;
      else cout << ans[i] << " ";
    }

  return 0;
}