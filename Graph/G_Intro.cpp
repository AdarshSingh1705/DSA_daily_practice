#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int V;
    bool directed;
    vector< vector<int> > adjList;

    public:
        Graph(int vertices, bool isdirected = false): V(vertices), directed(isdirected), adjList(vertices) {}

        void addEdge(int u, int v){
            if(u < 0 || v < 0 || u >= V || v >= V){ 
                cout << "Invalid edges: " << u << " " << v << endl;
                return;
            }
            adjList[u].push_back(v);

            // adding reverse edge for undirected graph
            if(!directed){
                adjList[v].push_back(u);
            }
        }

        void printGraph(){
            for(int i=0; i< V; i++){
                cout << i << " -> ";
                for(int neighbour : adjList[i]){
                    cout << neighbour << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    // Change false → true for directed graph
    Graph g(V, false);

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v); // Change to g.addEdge(u, v, false) for undirected
    }

    cout << "Adjacency List:" << endl;
    g.printGraph();

    return 0;
}