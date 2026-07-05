#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {

    unordered_map<char, int> mp;

    for (char ch : s) {
        mp[ch]++;
    }

    vector<pair<char, int>> freq(mp.begin(), mp.end());

    sort(freq.begin(), freq.end(),
        [](pair<char, int>& a, pair<char, int>& b) {

            if (a.second == b.second)
                return a.first < b.first;   // Alphabetical order

            return a.second > b.second;     // Higher frequency first
        });

    string ans = "";

    for (auto it : freq) {
        ans.append(it.second, it.first);
    }

    return ans;
}

int main() {

    string s;
    cin >> s;

    cout << frequencySort(s);

    return 0;
}