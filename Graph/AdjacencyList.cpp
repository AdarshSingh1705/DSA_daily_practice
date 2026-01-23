#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T> 
// if we have declared template then you don't have to write type of charcter or integer inside the class
// e.g: unordered_map<T, list<T> > adj; graph<int> g;

class graph{

public:
  unordered_map<int, list<int> > adj;

  void addEdges(int v, int u, bool direction){

    adj[u].push_back(v);
    if(!direction == 0){
        adj[v].push_back(u);
    }
  }

  void printing(){
    for(auto i : adj){
      cout << i.first << "->  ";
      for(auto j: i.second){
        cout << j << ", ";
      } 
      cout << endl;
    }
  }
};


int main(){
  int n;
  cout<< "Enter the number of Vertices: "<< endl;
  cin>> n;

  int m;
  cout<<"Enter the number of edges: " << endl;
  cin >> m;

  graph<int> g;

  // Creating undirected graph
  for(int i=0; i<m; i++){
    int v, u;
    cin >> v >> u;
    g.addEdges(v, u, false);
  }
  g.printing();

  return 0;
}