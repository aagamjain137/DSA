#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> mp;
    int l = 0;
    int maxLen = 0;
    for (int r = 0; r < fruits.size(); r++)
    {
        mp[fruits[r]]++;
        while (mp.size() > 2)
        {
            mp[fruits[l]]--;

            if (mp[fruits[l]] == 0) mp.erase(fruits[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}
int main()
{
    int n;
    cout << "Enter the number of trees: ";
    cin >> n;
    vector<int> fruits(n);
    cout << "Enter the fruits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }
    cout << "Maximum fruits collected = "
         << totalFruit(fruits);
    return 0;
}