#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int v) {
    vector<int> adjLs[v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    vector<int> vis(v, 0);
    int count = 0;
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            count++;
            dfs(i, adjLs, vis);
        }
    }
    return count;
}
int main() {
    int v = 3;
    vector<vector<int>> adj = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << numProvinces(adj, v) << endl;
    return 0;
}