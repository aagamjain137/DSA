#include <bits/stdc++.h>
using namespace std;

int numberofEnclaves(vector<vector<int>> grid){
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1 && vis[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}
int main(){
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = numberofEnclaves(grid);
    cout << "Number of enclaves: " << ans << endl;
    return 0;
}
// void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[]){
//     vis[row][col] = 1;
//     int n = grid.size();
//     int m = grid[0].size();
//     for (int i = 0; i < 4; i++){
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];
//         if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
//         {
//             dfs(nrow, ncol, vis, grid, delrow, delcol);
//         }
//     }
// }
// int numberofEnclaves(vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> vis(n, vector<int>(m, 0));
//     int delrow[] = {-1, 0, 1, 0};
//     int delcol[] = {0, 1, 0, -1};
//     for (int j = 0; j < m; j++)    {
//         if (!vis[0][j] && grid[0][j] == 1){
//             dfs(0, j, vis, grid, delrow, delcol);
//         }
//         if (!vis[n - 1][j] && grid[n - 1][j] == 1){
//             dfs(n - 1, j, vis, grid, delrow, delcol);
//         }
//     }
//     for (int i = 0; i < n; i++){
//         if (!vis[i][0] && grid[i][0] == 1){
//             dfs(i, 0, vis, grid, delrow, delcol);
//         }
//         if (!vis[i][m - 1] && grid[i][m - 1] == 1){
//             dfs(i, m - 1, vis, grid, delrow, delcol);
//         }
//     }
//     int count = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             if (grid[i][j] == 1 && !vis[i][j]){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
