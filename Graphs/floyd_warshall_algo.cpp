#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 1e9;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) {
                    continue;
                }
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(matrix[i][i] < 0) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}
int main() {

    int INF = 1e9;
    vector<vector<int>> matrix = {
        {0, 2, INF, INF},
        {1, 0, 3, INF},
        {INF, INF, 0, INF},
        {6, 5, 4, 0}
    };
    shortest_distance(matrix);
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[i].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}