#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
void changeTree(Node *root){
    if (root == NULL) return;
    int child = 0;
    if (root->left)child += root->left->val;
    if (root->right)child += root->right->val;
    if (child >= root->val)root->val = child;
    else    {
        if (root->left)
            root->left->val = root->val;
        else if (root->right)
            root->right->val = root->val;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total = 0;
    if (root->left)
        total += root->left->val;
    if (root->right)
        total += root->right->val;
    if (root->left || root->right)
        root->val = total;
}
void printTree(Node *root){
    if (root == NULL)
        return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
    Node *root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(10);
    root->left->left = new Node(50);
    root->left->right = new Node(70);
    root->right->left = new Node(5);
    root->right->right = new Node(60);
    changeTree(root);
    printTree(root);

    return 0;
}