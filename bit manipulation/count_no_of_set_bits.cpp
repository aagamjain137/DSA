#include<bits/stdc++.h>
using namespace std;

int CountSetBits(int n){
    int cnt = 0; 
    while(n > 1){
        cnt += n & 1;
        n = n >> 1;
    }
    if(n == 1) cnt += 1;
    return cnt;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of set bits = " << CountSetBits(n);
    return 0;
}