#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution{
public:
    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd,vector<int> &inorder, int inStart, int inEnd,
                        unordered_map<int, int> &inMap){
        if (preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder,preStart + 1,preStart + numsLeft,inorder,inStart,inRoot - 1,inMap);
        root->right = buildTree(preorder,preStart + numsLeft + 1,preEnd,inorder,inRoot + 1,inEnd,inMap);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)    {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)        {
            inMap[inorder[i]] = i;
        }
        return buildTree(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1,inMap);
    }
};
void printInorder(TreeNode *root){
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
void printPreorder(TreeNode *root){
    if (root == NULL)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution obj;
    TreeNode *root = obj.buildTree(preorder, inorder);
    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;
    cout << "Inorder: ";
    printInorder(root);
    cout << endl;
    return 0;
}