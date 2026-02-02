// #include <bits/stdc++.h>
#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
  int V;
  vector<vector<int>>adj;

  void dfs(vector<bool> &visited, stack<int>& st, int node){
    visited[node] = true;

    for(auto neighbour: adj[node]){
      if(!visited[neighbour]){
        dfs(visited, st, neighbour);
      }
    }

    st.push(node); // post order insertion
  }

public:

  Graph(int vertices){
    V = vertices;
    adj.resize(V);
  }

  void addEdges(int u, int v){
    adj[u].push_back(v);
  }

  void  topoSort(){
    vector<bool> visited(V, false);
    stack<int> st;

    for(int i=0; i< V; i++){
      if(!visited[i]){
        dfs(visited, st, i);
      }
    }

    cout << "Topological Order: "<< endl;
    while(!st.empty()){
      cout << st.top() << ", ";
      st.pop();
    }

  }

};


int main(){

  Graph g(6);

  g.addEdges(5, 2);
  g.addEdges(5, 0);
  g.addEdges(4, 0);
  g.addEdges(4, 1);
  g.addEdges(2, 3);
  g.addEdges(3, 1);

  g.topoSort();

  return 0;
}