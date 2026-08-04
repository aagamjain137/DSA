#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> hash(256, -1);
    int n = s.length();
    int l = 0, r = 0;
    int maxLen = 0;

    while (r < n)
    {
        if (hash[s[r]] != -1 && hash[s[r]] >= l)
        {
            l = hash[s[r]] + 1;
        }

        int len = r - l + 1;
        maxLen = max(maxLen, len);

        hash[s[r]] = r;
        r++;
    }
    return maxLen;
}
int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of the longest substring = " << lengthOfLongestSubstring(s);
    return 0;
}