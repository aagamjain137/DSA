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
void recursion(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
    {
        ans.push_back(root->val);
    }
    recursion(root->right, level + 1, ans);
    recursion(root->left, level + 1, ans);
}
vector<int> leftSideView(Node *root)
{
    vector<int> ans;
    recursion(root, 0, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->left->right->left = new Node(6);

    vector<int> result = leftSideView(root);
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}