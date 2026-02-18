// Time Complexity?
// O(V + E)

// Space Complexity?
// O(V + E)

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

class Kosaraju{
public:
    int V;
    vector<vector<int>> adj;
    stack<int> st;
    vector<bool> visited;
    vector<vector<int>> ans;

    Kosaraju(int V){
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void dfs1(int node){
        visited[node] = true;

        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                dfs1(neigh);
            }
        }
        st.push(node); // Fininshing time
    }

    void dfs2(int node, vector<vector<int>> &revAdj, vector<int> &component){
        visited[node] = true;
        component.push_back(node);

        for(auto neigh : revAdj[node]){
            if(!visited[neigh]){
                dfs2(neigh, revAdj, component);
            }
        }
    }

    void findSCC(){
        
        // Step 1: fill stack by finishing time
        for(int i=0; i < V; i++ ){
            if(!visited[i]){
                dfs1(i);
            }
        }

        vector<vector<int>> revAdj(V);
        // Step 2:  reverse graph
        for(int i=0; i<V; i++){
            for(auto v : adj[i]){
                revAdj[v].push_back(i);
            }
        }

        // Reset visited
        fill(visited.begin(), visited.end(), false);

        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                vector<int> component;
                dfs2(node, revAdj, component);
                ans.push_back(component);
            }
        }
    }
};

int main(){
    int V, E;
    cin >> V >> E;

    Kosaraju ksr(V);
    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        ksr.addEdge(u, v);
    }

    ksr.findSCC();

    // Print SCCs
    // cout << "Strongly Connected Components:\n";
    for(auto &comp : ksr.ans){
        for(auto node : comp){
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}