#include<bits/stdc++.h>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }
    void push(int value){
        if(rear == 99){
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        cout << value << " inserted into queue." << endl;
    }
    void pop(){
        if(front > rear){
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;
        front++;
    }
    int top(){
        if(front > rear){
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }
};

int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element : " << q.top() << endl;

    q.pop();
    cout << "Front element : " << q.top() << endl;
    return 0;
}