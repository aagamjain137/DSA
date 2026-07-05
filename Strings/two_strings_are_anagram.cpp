#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length())
        return false;

    unordered_map<char, int> mp;

    for (char ch : s) {
        mp[ch]++;
    }

    for (char ch : t) {
        mp[ch]--;
    }

    for (auto it : mp) {
        if (it.second != 0)
            return false;
    }

    return true;
}
int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "Anagram";
    else
        cout << "Not Anagram";

    return 0;
}