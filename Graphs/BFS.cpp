#include<bits/stdc++.h>
using namespace std;

vector<int>bfsOfGraph(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main() {
    int v = 5;
    vector<int> adj[v];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(1);

    vector<int> bfs = bfsOfGraph(v, adj);
    for(int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }
    return 0;
}