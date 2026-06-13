#include <iostream>
using namespace std;

int main(){
    int rows = 5;
    // cout << "Enter number of rows" << endl;
    // cin >> rows;
    for(int i = 1;i<=rows;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5 