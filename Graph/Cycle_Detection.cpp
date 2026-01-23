#include <bits/stdc++.h>
using namespace std;

// =-=-=-=-=-==-=- BFS version implementation =-=-=-=-=-=-=-=-=-=-=-=
class Graph {
public:
    int V;
    vector<vector<int>> adj;
    vector<int> visited, parent;

    Graph(int v) {
        V = v;
        adj.resize(V);
        visited.assign(V, 0);
        parent.assign(V, -1);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    bool isCycleBFS(int start) {
        queue<int> q;
        visited[start] = 1;
        parent[start] = -1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
                else if (neighbor != parent[node]) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

    bool hasCycle() {
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleBFS(i)) return true;
            }
        }
        return false;
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j : adj[i]){
              cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout<< "Enter number of nodes: " << endl;
    cin >> V;

    cout << "Enter number of edges: "<< endl;
    cin >> E;

    Graph g(V);

    cout << "Enter edges: " << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.hasCycle()){
        cout << "Cycle exists\n";
    }
    else{
        cout << "No cycle\n";
    }

    return 0;
}

// =-=-=-=-=-==-=- DFS version implementation =-=-=-=-=-=-=-=-=-=-=-=

// class Graph {
// public:
//     unordered_map<int, list<int>> adj;
//     unordered_map<int, bool> visited;

//     void addEdge(int u, int v, bool directed = false) {
//         adj[u].push_back(v);
//         if (!directed) {
//             adj[v].push_back(u);
//         }
//     }

//     bool dfsCycle(int node, int parent) {
//         visited[node] = true;

//         for (auto neighbor : adj[node]) {
//             if (!visited[neighbor]) {
//                 if (dfsCycle(neighbor, node)) {
//                     return true;
//                 }
//             }
//             else if (neighbor != parent) {
//                 return true; // cycle found
//             }
//         }
//         return false;
//     }

//     bool hasCycle(int V) {
//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 if (dfsCycle(i, -1)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     void printGraph() {
//         for (auto &i : adj) {
//             cout << i.first << " -> ";
//             for (auto j : i.second) {
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//     }
// };