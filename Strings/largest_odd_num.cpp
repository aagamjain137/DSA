#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {

    for (int i = num.length() - 1; i >= 0; i--) {

        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }

    return "";
}

int main() {
    string num;

    cout << "Enter number: ";
    cin >> num;

    cout << "Largest Odd Number: " << largestOddNumber(num);

    return 0;
}