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

Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);

    newNode->next = head;
    head = newNode;

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

    cout << "Before Insertion: ";
    printList(head);

    head = insertAtHead(head, 5);

    cout << "After Insertion: ";
    printList(head);

    return 0;
}