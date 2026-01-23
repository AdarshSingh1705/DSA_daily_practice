#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;
    bool directed;
    vector< vector<int>> adjlist;

public:
    Graph(int vertices, bool isdirected = false) 
            : V(vertices), directed(isdirected), adjlist(vertices){}

    void addEdges(int u, int v){
        if(u < 0 || v < 0 || u >= V || v >= V){
            cerr << "Invalid edge: " << u << " " << v << endl;
            return;
        }

        adjlist[u].push_back(v);

        if(!directed){
            adjlist[v].push_back(u);
        }
    }

    void BFS(int start){
        if(start < 0 || start >= V){
            cerr << "Invalid BFS start node: " << start << endl;
            return;
        }

        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";

            for(int neighbour : adjlist[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        cout << endl;
    }

    void printGraph(){
        for(int i=0; i<V; i++){
            cout << i << " ->";
            for(int neighbour: adjlist[i]){
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
};

int main(){
    int V, E;
    cout << "Enter the vertices: ";
    cin >> V;

    Graph g(V); // undirected by default

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges (u, v): " << endl;
    for(int i=0; i < E; i++){
        int u, v;
        cin >> u >> v;
        g.addEdges(u, v);
    }

    cout << "Adjacency List: " << endl;
    g.printGraph();

    int start;
    cout << "Enter BFS start node: ";
    cin >> start;

    g.BFS(start);

    return 0;
}


// void prepareList(unordered_map<int, list<int>> &adjlist, const vector<pair<int, int>> &edges) {
//     for (auto &p : edges) {
//         int u = p.first;
//         int v = p.second;

//         adjlist[u].push_back(v);
//         adjlist[v].push_back(u); // undirected
//     }
// }


// void bfs(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int>& ans, int node){
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while(!q.empty()){
//         int front = q.front();
//         q.pop();
        
//         ans.push_back(front);
//         for(auto i:adjlist[front]){
//             if(!visited[i]){
//                 q.push(i);
//                 visisted[i] = true;
//             }
//         }
//     }
// }

// vector<int> BFS(int vertex, const vector<pair<int, int>> &edges) {
//     unordered_map<int, list<int>> adjlist;
//     unordered_map<int, bool> visited;
//     vector<int> ans;

//     preparelist(adjlist, edges);
//     for(int i=0; i < vertex; i++){
//         if(!visited[i]){
//             bfs(adjlist, visited, ans, i);
//         }
//     }
//   return ans;
// }