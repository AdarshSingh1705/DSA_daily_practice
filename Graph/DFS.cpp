
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class graph{

public:
  unordered_map<int, list<int> >adj;
  unordered_map<int, bool> visited;
  int V;

  graph(int v){
    V = v;
  }

  void addEdges(int v, int u, bool direction = false){

    adj[u].push_back(v);

    if(!direction){
      adj[v].push_back(u);
    }
  }

  void dfs(int node, vector<int>& component){

    component.push_back(node);
    visited[node] = true;

    for(auto neighbour : adj[node]){
      if(!visited[neighbour]){
        dfs(neighbour, component);
      }
    }
  }

  vector<vector<int>> getComponent(){
    
    vector<vector<int>>ans;

    for(int i=0; i< V; i++){
      if(!visited[i]){
        vector<int> component;
        dfs(i, component);
        ans.push_back(component);
      }
    }
    return ans;
  }

  void printing(){
    for(auto& i : adj){
      cout << i.first << " ->  ";
      for(auto& j: i.second){
        cout << j << ", ";
      } 
      cout << endl;
    }
  }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  int V, E;
  cout<< "Enter the number of Vertices: "<< endl;
  cin>> V;

  cout<<"Enter the number of edges: " << endl;
  cin >> E;

  graph g(V);

  // Creating undirected graph
  for(int i=0; i<E; i++){
    int v, u;
    cin >> v >> u;
    g.addEdges(v, u, false);
  }
  g.printing();

  vector<vector<int>> components = g.getComponent();

  cout << "\n Connected Components: ";
  for(auto& comp : components){
    for(int node : comp){
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}