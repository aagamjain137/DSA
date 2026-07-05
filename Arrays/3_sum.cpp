#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        unordered_set<int> hashSet;

        for (int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);

            if (hashSet.find(third) != hashSet.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashSet.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

    cout << "Triplets are:\n";
    for (auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}