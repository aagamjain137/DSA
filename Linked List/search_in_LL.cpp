#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

bool searchInLL(Node* head, int key) {

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data == key)
            return true;

        temp = temp->next;
    }

    return false;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    if (searchInLL(head, key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}