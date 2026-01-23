#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source){
  vector<vector<pair<int, int>>> adj(vertices);
  
  for(int i=0; i< edges; i++){
      int u = vec[i][0];
      int v = vec[i][1];
      int w = vec[i][2];

      adj[u].push_back({v, w});
      adj[v].push_back({u, w}); // remove this for directed graph
  }   
  vector<int> dist(vertices, INT_MAX);
  set<pair<int, int>> st;
  
  dist[source] = 0;
  st.insert({0, source});

  while(!st.empty()){

    auto top = *(st.begin());
    st.erase(st.begin());

    int nodeDistance = top.first;
    int topNode = top.second;

    for(auto neighbour: adj[topNode]){
      
      int neighbourNode = neighbour.first;
      int neighbourNodeWeight = neighbour.second;

      if(nodeDistance + neighbourNodeWeight < dist[neighbourNode]){
        
        if(dist[neighbourNode] != INT_MAX){
          st.erase({dist[neighbourNode], neighbourNode});
        }
        dist[neighbourNode] = nodeDistance + neighbourNodeWeight;
        st.insert({dist[neighbourNode], neighbourNode});
      }
    }
  }
  return dist;
}

int main() {
    int vertices = 5;
    int edges = 6;
    int source = 0;

    vector<vector<int>> vec = {
        {0,1,2},
        {0,2,4},
        {1,2,1},
        {1,3,7},
        {2,4,3},
        {3,4,1}
    };

    vector<int> dist = dijkstra(vec, vertices, edges, source);

    for (int i = 0; i < vertices; i++)
        cout << i << " -> " << dist[i] << endl;
}


// USing Priority Queue == better cache locality, tree rotations + pointer chasing

// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source){

//     // ✅ Adjacency list
//     vector<vector<pair<int,int>>> adj(vertices);

//     for(int i = 0; i < edges; i++){
//         int u = vec[i][0];
//         int v = vec[i][1];
//         int w = vec[i][2];

//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});   // remove this for directed graph
//     }

//     // ✅ Min-heap: (distance, node)
//     priority_queue< pair<int,int>, vector<pair<int,int>>,  greater<pair<int,int>> > pq;

//     vector<int> dist(vertices, INT_MAX);

//     dist[source] = 0;
//     pq.push({0, source});

//     while(!pq.empty()){

//         auto top = pq.top();
//         pq.pop();

//         int nodeDistance = top.first;
//         int topNode = top.second;

//         // ✅ Ignore stale heap entries
//         if(nodeDistance > dist[topNode]) continue;

//         for(auto &neighbour : adj[topNode]){

//             int neighbourNode  = neighbour.first;
//             int neighbourNodeWeight = neighbour.second;

//             if(nodeDistance + neighbourNodeWeight < dist[neighbourNode]){

//                 dist[neighbourNode] = nodeDistance + neighbourNodeWeight;
//                 pq.push({dist[neighbourNode], neighbourNode});
//             }
//         }
//     }

//     return dist;
// }
