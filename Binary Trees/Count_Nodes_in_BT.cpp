#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
int findHeightLeft(Node* root){
    int height = 0;
    while (root)    {
        height++;
        root = root->left;
    }
    return height;
}
int findHeightRight(Node* root){
    int height = 0;
    while (root)    {
        height++;
        root = root->right;
    }
    return height;
}
int countNodes(Node *root){
    if(root == NULL) return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if(lh == rh) return (1<<lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    cout << countNodes(root);
    return 0;
}