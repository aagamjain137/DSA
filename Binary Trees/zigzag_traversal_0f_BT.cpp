#include <bits/stdc++.h>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;
    queue<TreeNode *> nodesQueue;
    nodesQueue.push(root);
    bool leftToright = true;
    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = nodesQueue.front();
            nodesQueue.pop();
            int idx = (leftToright) ? i : (size - 1 - i);
            row[idx] = node->val;
            if (node->left)
                nodesQueue.push(node->left);
            if (node->right)
                nodesQueue.push(node->right);
        }
        leftToright = !leftToright;
        result.push_back(row);
    }
    return result;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    vector<vector<int>> result = zigzagLevelOrder(root);
    for (const auto level : result) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}