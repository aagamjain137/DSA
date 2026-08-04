#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0, sum = 0, cnt = 0;
    while (r < nums.size())
    {
        sum += nums[r] % 2;
        while (sum > k)
        {
            sum -= nums[l] % 2;
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return atMost(nums, k) - atMost(nums, k - 1);
}
int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Number of nice subarrays = "
         << numberOfSubarrays(nums, k);
    return 0;
}