#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int l = 0, r = 0, zeros = 0;
    int maxLen = 0;

    while (r < nums.size())
    {
        if (nums[r] == 0) zeros++;
        while (zeros > k)
        {
            if (nums[l] == 0)zeros--;
                l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements (0s and 1s): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Maximum consecutive ones = "
         << longestOnes(nums, k);

    return 0;
}