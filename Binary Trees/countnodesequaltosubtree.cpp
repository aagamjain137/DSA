#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
vector<pair<int, int>> dfs(TreeNode *root, int &ans){
    if (root == NULL)    {
        return { {0, 0} };
    }
    auto left = dfs(root->left, ans);
    auto right = dfs(root->right, ans);
    int sum = left[0].first + right[0].first + root->val;
    int count = left[0].second + right[0].second + 1;
    if (sum / count == root->val){
        ans++;
    }
    return { {sum, count} };
}
int averageOfSubtree(TreeNode *root){
    int ans = 0;
    dfs(root, ans);
    return ans;
}
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    int result = averageOfSubtree(root);
    cout << "Number of nodes equal to the average of their subtree: " << result << endl;

    return 0;
}