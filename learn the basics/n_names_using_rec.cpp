#include <iostream>
using namespace std;

void printName(int i, int n) {

    if(i > n)
        return;

    cout << "Aagam" << endl;

    printName(i + 1, n);
}

int main() {

    int n = 5;

    printName(1, n);

    return 0;
}
