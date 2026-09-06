#include <bits/stdc++.h>
using namespace std;

void kadane(vector<int>& arr) {
    int sum = 0;
    int maxi = INT_MIN;

    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;

    for (int i = 0; i < arr.size(); i++) {

        if (sum == 0)
            start = i;

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
            sum = 0;
    }

    cout << "Maximum Subarray Sum = " << maxi << endl;
    cout << "Start Index = " << ansStart << endl;
    cout << "End Index = " << ansEnd << endl;

    cout << "Subarray: ";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    kadane(arr);

    return 0;
}