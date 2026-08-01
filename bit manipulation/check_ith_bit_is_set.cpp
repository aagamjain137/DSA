#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    cout << "enter value : " ;
    cin >> n ;
    cout << "enter index value : ";
    cin >> i ;
    if((n >> i) & 1){
        cout << "Set";
    }else
        cout << "Not set";

    return 0;
}