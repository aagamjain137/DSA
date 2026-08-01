#include <iostream>
using namespace std;

int helper(string &s, int n) {
    if (n == 0)
        return 0;
 
    return helper(s, n - 1) * 10 + (s[n - 1] - '0');
}

int atoiRecursive(string s) {
    if (s[0] == '-')
        return -helper(s, s.length() - 1);

    return helper(s, s.length());
}

int main() {
    cout << atoiRecursive("-567") << endl;
}