#include <iostream>
using namespace std;

long long power(long long x, long long n) {
    long long ans = 1;

    while (n > 0) {
        if (n % 2 == 1)
            ans *= x;

        x *= x;
        n /= 2;
    }

    return ans;
}

int main() {
    cout << power(2, 5) << endl; // 32
    return 0;
}