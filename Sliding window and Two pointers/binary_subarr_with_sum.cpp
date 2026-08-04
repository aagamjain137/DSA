#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int goal)
{
    if (goal < 0) return 0;
    int l = 0, r = 0, sum = 0, cnt = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
int main()
{
    int n, goal;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements (0 and 1): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the goal: ";
    cin >> goal;
    cout << "Number of subarrays = "
         << numSubarraysWithSum(nums, goal);

    return 0;
}