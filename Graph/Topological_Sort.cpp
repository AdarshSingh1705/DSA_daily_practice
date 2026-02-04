// #include <bits/stdc++.h>

// Topological Sort is a linear ordering of vertices such that for every edges u->v, u always appears before v in that ordering


// ================ Topological Sort using DFS ====================
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



// ============== Topo Sort Using Kahn's Algorithm +++++++++++++

// #include <bits/stdc++.h>
// using namespace std;

// class Graph {
// private:
//     int V;
//     vector<vector<int>> adj;

// public:
//     Graph(int vertices) {
//         V = vertices;
//         adj.resize(V);
//     }

//     void addEdge(int u, int v) {
//         // directed edge u -> v
//         adj[u].push_back(v);
//     }

//     vector<int> topologicalSort() {
//         vector<int> indegree(V, 0);

//         // Step 1: Compute indegree of each node
//         for (int u = 0; u < V; u++) {
//             for (int v : adj[u]) {
//                 indegree[v]++;
//             }
//         }

//         // Step 2: Push nodes with indegree 0
//         queue<int> q;
//         for (int i = 0; i < V; i++) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         vector<int> topo;

//         // Step 3: BFS
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             topo.push_back(node);

//             for (int v : adj[node]) {
//                 indegree[v]--;
//                 if (indegree[v] == 0) {
//                     q.push(v);
//                 }
//             }
//         }

//         // Step 4: Cycle detection
//         if (topo.size() != V) {
//             return {}; // cycle exists
//         }

//         return topo;
//     }
// };

// int main() {
//     Graph g(6);

//     g.addEdge(5, 2);
//     g.addEdge(5, 0);
//     g.addEdge(4, 0);
//     g.addEdge(4, 1);
//     g.addEdge(2, 3);
//     g.addEdge(3, 1);

//     vector<int> topo = g.topologicalSort();

//     if (topo.empty()) {
//         cout << "Cycle detected. Topological sort not possible\n";
//     } else {
//         cout << "Topological Order: ";
//         for (int x : topo)
//             cout << x << " ";
//     }

//     return 0;
// }
