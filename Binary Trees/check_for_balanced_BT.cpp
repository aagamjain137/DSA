#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
int dfsHeight(TreeNode* root){
    if(root == NULL) return 0;

    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = dfsHeight(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight-rightHeight)>1) return -1;
    return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(TreeNode *root)
{
    return dfsHeight(root) != -1;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right =new TreeNode(5);
    cout << isBalanced(root) << endl;
    return 0;
}
