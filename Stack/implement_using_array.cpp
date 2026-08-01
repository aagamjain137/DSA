#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int topIndex;

public:
    // Constructor
    Stack() {
        topIndex = -1;
    }

    // Push operation
    void push(int value) {
        if (topIndex == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }

        topIndex++;
        arr[topIndex] = value;
        cout << value << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {
        if (empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << arr[topIndex] << " popped from stack." << endl;
        topIndex--;
    }

    // Peek operation
    void peek() {
        if (empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element is: " << arr[topIndex] << endl;
    }

    // Top operation
    int top() {
        if (empty()) {
            return -1;
        }

        return arr[topIndex];
    }

    // Empty operation
    bool empty() {
        return topIndex == -1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    cout << "Top element: " << s.top() << endl;

    s.pop();

    s.peek();

    if (s.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}