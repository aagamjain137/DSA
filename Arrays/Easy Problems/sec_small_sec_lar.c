#include <stdio.h>
#include <limits.h>

void findSecondSmallestLargest(int arr[], int n) {
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {

        // Smallest and Second Smallest
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }

        // Largest and Second Largest
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest = %d\n", secondSmallest);
    printf("Second Largest = %d\n", secondLargest);
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSecondSmallestLargest(arr, n);

    return 0;
}