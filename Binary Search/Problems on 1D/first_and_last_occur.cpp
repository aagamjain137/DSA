#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // left search
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurrence(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // right search
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return last;
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
    cout << "Enter target: ";
    cin >> x;

    int first = firstOccurrence(arr, n, x);
    int last = lastOccurrence(arr, n, x);

    cout << "First Occurrence = " << first << endl;
    cout << "Last Occurrence = " << last << endl;

    return 0;
}