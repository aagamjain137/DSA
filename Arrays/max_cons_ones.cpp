#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int maxCount = 0;
    for (int num : nums) {
        if (num == 1) {
            count++;
        } else {
            count = 0;
        }

        maxCount = max(maxCount, count);
    }
    return maxCount;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter only 0 and 1:\n";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        if (nums[i] != 0 && nums[i] != 1) {
            cout << "Invalid input! Only 0 and 1 are allowed.";
            return 0;
        }
    }
    cout << "Maximum consecutive ones = "
         << findMaxConsecutiveOnes(nums);

    return 0;
}