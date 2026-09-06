#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int floorVal = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            floorVal = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return floorVal;
}

int findCeil(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ceilVal = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ceilVal = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ceilVal;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter element: ";
    cin >> x;

    cout << "Floor = " << findFloor(arr, n, x) << endl;
    cout << "Ceil = " << findCeil(arr, n, x) << endl;

    return 0;
}