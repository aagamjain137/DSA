#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int maxDepth(TreeNode* root){
    if(root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Max Depth of Binary Tree: " << maxDepth(root) << endl;
    return 0;
}