// #include <bits/stdc++.h>
// using namespace std;

// int missingNum(vector<int>& arr) {
//     int n = arr.size() + 1;

//     int expectedSum = n * (n + 1) / 2;
//     int actualSum = 0;

//     for (int num : arr) {
//         actualSum += num;
//     }

//     return expectedSum - actualSum;
// }

// int main() {
//     int n;

//     cout << "Enter value of N: ";
//     cin >> n;

//     vector<int> arr(n - 1);

//     cout << "Enter " << n - 1 << " elements: ";
//     for (int i = 0; i < n - 1; i++) {
//         cin >> arr[i];
//     }

//     cout << "Missing Number: " << missingNum(arr) << endl;

//     return 0;
// }

#include <stdio.h>

int missingNum(int arr[], int size) {
    int n = size + 1;

    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int n;

    printf("Enter value of N: ");
    scanf("%d", &n);

    int arr[n - 1];

    printf("Enter %d elements: ", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Missing Number: %d\n", missingNum(arr, n - 1));

    return 0;
}