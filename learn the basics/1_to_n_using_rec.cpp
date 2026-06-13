#include <iostream>
using namespace std;

void Printnumber(int i, int n) {
    if(i > n)
        return;
    cout << i << " ";
    Printnumber(i + 1, n);
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Printnumber(1, n);
    return 0;
}
