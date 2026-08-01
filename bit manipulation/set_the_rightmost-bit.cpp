#include<bits/stdc++.h>
using namespace std;


int setBit(int n){
    {
        return n | (n + 1);
    }
}
int main(){
    int n;
    cout << "enter a number:";
    cin >> n;
    cout << "set bit = " << setBit(n);
    return 0;
} 
