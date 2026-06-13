#include <iostream>
using namespace std;

void reverseArray(int arr[], int left, int right){
    if(left >= right)
        return;
    swap(arr[left], arr[right]);
    reverseArray(arr, left + 1, right - 1);

}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    reverseArray(arr, 0, n-1);
    cout << "Reversed array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;   
}

// #include <stdio.h>
// void reverseArray(int arr[], int left, int right){
//     int temp;
//     if(left >= right)
//         return;
//     temp = arr[left];
//     arr[left] = arr[right];
//     arr[right] = temp;
//     reverseArray(arr, left + 1, right - 1);
// }

// int main(){
//     int arr[] = {1,2,3,4,5};
//     int n = 5;
//     reverseArray(arr, 0, n-1);
//     printf("Reversed array: ");
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;   
// }