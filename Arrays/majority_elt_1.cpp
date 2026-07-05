#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {

    unordered_map<int, int> mp;

    for (int num : nums) {
        mp[num]++;
    }

    int n = nums.size();

    for (auto it : mp) {
        if (it.second > n / 2)
            return it.first;
    }

    return -1;
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = majorityElement(nums);

    if (ans != -1)
        cout << "Majority Element = " << ans;
    else
        cout << "No Majority Element";

    return 0;
}