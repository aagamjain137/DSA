#include <bits/stdc++.h>
using namespace std;

// Insert an element into its correct position in the sorted stack
void insertSorted(stack<int> &st, int x)
{
    if (st.empty() || st.top() <= x)
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertSorted(st, x);

    st.push(temp);
}

// Sort the stack using recursion
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int temp = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, temp);
}

// Print stack (Top to Bottom)
void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;

    st.push(2);
    st.push(4);
    st.push(1);
    st.push(3);

    cout << "Original Stack (Top to Bottom): ";
    printStack(st);

    sortStack(st);

    cout << "Sorted Stack (Top to Bottom): ";
    printStack(st);

    return 0;
}