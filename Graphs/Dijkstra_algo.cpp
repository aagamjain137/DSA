#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v);
    for (int i = 0; i < v; i++)
        dist[i] = 1e9;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgeweight = it[1];
            int adjnode = it[0];
            if (dis + edgeweight < dist[adjnode])
            {
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}
int main()
{
    int v = 5;
    vector<vector<int>> adj[v];
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});
    vector<int> dist = dijkstra(v, adj, 0);
    for (int i = 0; i < v; i++)
        cout << dist[i] << " ";
    return 0;
}