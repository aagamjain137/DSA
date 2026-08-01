#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();

    InsertAtBottom(s,element);
    s.push(num);
}
void reverseStack(stack<int> & stack){
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    InsertAtBottom(stack,num);
}
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

    reverseStack(st);

    cout << "Reversed Stack (Top to Bottom): ";
    printStack(st);

    return 0;
}