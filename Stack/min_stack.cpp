#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> st;
    stack<int> minSt;

public:
    void push(int val)
    {
        st.push(val);

        if (minSt.empty() || val <= minSt.top())
        {
            minSt.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
        {
            cout << "Stack is empty\n";
            return;
        }

        if (st.top() == minSt.top())
        {
            minSt.pop();
        }

        st.pop();
    }
    int top()
    {
        if (st.empty())
        {
            return -1;
        }

        return st.top();
    }
    int getMin()
    {
        if (minSt.empty())
        {
            return -1;
        }

        return minSt.top();
    }
};
int main()
{
    MinStack s;
    s.push(5);
    s.push(2);
    s.push(10);
    s.push(1);
    cout << "Minimum element = " << s.getMin() << endl;
    s.pop();
    cout << "Minimum element = " << s.getMin() << endl;
    return 0;
}