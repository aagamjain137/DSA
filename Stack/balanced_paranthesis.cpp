#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
    stack<char> s;

    for (char ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {

            if (s.empty())
            {
                return false;
            }

            if ((ch == ')' && s.top() == '(') ||
                (ch == '}' && s.top() == '{') ||
                (ch == ']' && s.top() == '['))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return s.empty();
}
int main()
{
    string str;
    cout << "Enter the expression: ";
    cin >> str;

    if (isBalanced(str))
    {
        cout << "Balanced Parentheses";
    }
    else
    {
        cout << "Not Balanced";
    }
    return 0;
}