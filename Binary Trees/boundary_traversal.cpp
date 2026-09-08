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
bool isLeaf(Node *node){
    return(node->left== NULL && node->right == NULL);
}
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* current = root->left;
    while(current){
        if(!isLeaf(current))
            res.push_back(current->val);
        if(current->left)
            current = current->left;
        else
            current = current->right;
    }
}
void addRightBoundary(Node*root, vector<int>& res) {
    Node* current = root->right;
    vector<int> temp;
    while(current){
        if(!isLeaf(current))
            temp.push_back(current->val);
        if(current->right)
            current = current->right;
        else
            current = current->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
        res.push_back(temp[i]);
}
void addLeaves(Node* root, vector<int>& res) {
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left)
        addLeaves(root->left,res);
    if(root->right)
        addLeaves(root->right,res);
}
vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if(!root)
        return res;
    if(!isLeaf(root))
        res.push_back(root->val);
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int> result = boundaryTraversal(root);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}