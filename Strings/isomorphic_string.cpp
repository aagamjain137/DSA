#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {

    if (s.length() != t.length())
        return false;

    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for (int i = 0; i < s.length(); i++) {

        char c1 = s[i];
        char c2 = t[i];

        if (mp1.count(c1)) {
            if (mp1[c1] != c2)
                return false;
        }
        else {
            mp1[c1] = c2;
        }

        if (mp2.count(c2)) {
            if (mp2[c2] != c1)
                return false;
        }
        else {
            mp2[c2] = c1;
        }
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isIsomorphic(s, t))
        cout << "Isomorphic";
    else
        cout << "Not Isomorphic";

    return 0;
}