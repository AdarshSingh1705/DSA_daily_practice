#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent, rank;

public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY){
            return false;
        }

        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        }
        else if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

class Solution{
public:

    int kruskal(int V, vector<vector<int> > &edges){
        sort(edges.begin(), edges.end(), [](auto &a, auto 
        &b){
            return a[2] > b[2];
        });

        DSU dsu(V);
        int mstCost = 0;
        int edgesUsed =0;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dsu.unite(u, v)){
                mstCost += w;
                edgesUsed++;

                if(edgesUsed == V-1){
                    break;
                }
            }
        }
        return mstCost;
    }
};

int main() {
    int V = 4; // number of vertices
    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {2, 3, 3}
    };
    Solution sol;

    int mstWeight = sol.kruskal(V, edges);
    cout << "Total weight of MST = " << mstWeight << endl;

    return 0;
}

