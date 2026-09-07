#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        dist[u][v] = wt;
        dist[v][u] = wt;
    }
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int cntCity = INT_MAX;
    int cityNo = -1;
    for (int city = 0; city < n; city++)
    {
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++)
        {
            if (dist[city][adjCity] <= distanceThreshold)
                cnt++;
        }
        if (cnt <= cntCity)
        {
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}
int main()
{
    int n = 4;
    int m = 5;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 3, 4},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 1}};
    int distanceThreshold = 4;
    int cityNo = findCity(n, m, edges, distanceThreshold);
    cout << "The city with the smallest number of neighbors " << "within the distance threshold is: " << cityNo << endl;
    return 0;
}