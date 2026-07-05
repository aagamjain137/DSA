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

Node* deleteHead(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before Deletion: ";
    printList(head);

    head = deleteHead(head);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}