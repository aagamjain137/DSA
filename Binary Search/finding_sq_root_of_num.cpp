#include <bits/stdc++.h>
using namespace std;

int findSqrt(int n) {
    int low = 1, high = n;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Square Root = " << findSqrt(n);

    return 0;
}