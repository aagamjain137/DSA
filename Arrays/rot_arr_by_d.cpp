#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d;
    cout << "Enter number of rotations: ";
    cin >> d;
    d = d % n;

    for (int i = 0; i < d; i++) {
        int temp = arr[0];

        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }

        arr[n - 1] = temp;
    }
    cout << "Rotated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}