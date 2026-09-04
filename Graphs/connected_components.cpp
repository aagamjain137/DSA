#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}
int connectedcomponents(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(V, 0);
    int cnt = 0;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i, adj, vis);
        }
    }
    return cnt;
}
int main(){
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 4}};
    cout << connectedcomponents(V, edges) << endl;
    return 0;
}