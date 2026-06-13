#include <iostream>
using namespace std;

int main(){
    int rows = 5;
    int count = 0;
    for(int i = 1;i<=rows;i++){
        for(int j=1;j<=i;j++){
            count++;
            cout << count << " ";
        }
        cout << endl;
    }
}

// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15 
