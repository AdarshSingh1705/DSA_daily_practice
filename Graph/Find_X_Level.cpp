#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph{
public:
  int V;
  vector<vector<int>> adj;

  Graph(int v){
    V = v;
    adj.resize(V);
  }

void addEdges(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

int findX(int src, int x){

  vector<bool> visited(V, false);
  queue<int> q;
  q.push(src);
  int cnt = 0;

  while(!q.empty()){
      int size = q.size();
      cnt++;
      while(size--){
        int node = q.front();
        q.pop();

        if(x == node){
          return cnt;
        }
        for(int neigh : adj[node]){
          if(!visited[neigh]){
            visited[neigh] = true;
            q.push(neigh);
          }
        }

      }
  }

  return -1;
}

};

int main(){

  cout<<"Enter V and E" << endl;
   int V, E;
   cin >> V >> E;
  Graph g(V);
  cout<< "Enter u, v of edges: "<< endl;
   for(int i=0; i<E; i++){
    int u, v;
    cin >> u >> v;
    g.addEdges(u, v);
   }
   cout<<"Enter X: "<<endl;
   int x; cin >> x;

   cout << g.findX(0, x) << endl;

  return 0;
}