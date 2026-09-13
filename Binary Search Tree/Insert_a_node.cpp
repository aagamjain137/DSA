#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
TreeNode *insertIntoBST(TreeNode *root, int val){
    if (root == NULL)
        return new TreeNode(val);
    TreeNode *cur = root;
    while (true){
        if (cur->val <= val){
            if (cur->right != NULL)
                cur = cur->right;
            else            {
                cur->right = new TreeNode(val);
                break;
            }
        }
        else {
            if (cur->left != NULL)
                cur = cur->left;
            else{
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}
void printInorder(TreeNode *root){
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
   
    int val = 10;

    root = insertIntoBST(root, val);
    printInorder(root);
    return 0;
}