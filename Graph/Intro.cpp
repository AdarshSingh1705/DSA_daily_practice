#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector< vector<int> > adjList;

    public:
        Graph(int vertices){
            V = vertices;
            adjList.resize(V);
        }

        void addEdge(int u, int v, bool directed = true){
            adjList[u].push_back(v);
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
    Graph g(V);

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

class graph{
public:
    int V;
    vector<vector<int>> Adj;

    graph(int v){
        this ->V = v;
        Adj.resize(V);
    }
};