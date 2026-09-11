#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int findMaxDistance(map<BinaryTreeNode *, BinaryTreeNode *> &mpp,BinaryTreeNode *target){
    queue<BinaryTreeNode *> q;
    q.push(target);
    map<BinaryTreeNode *, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty())    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)        {
            BinaryTreeNode *node = q.front();
            q.pop();
            if (node->left && !vis[node->left])            {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right])            {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] && !vis[mpp[node]])            {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl) maxi++;
    }
    return maxi;
}
BinaryTreeNode *bfsToMapParents(BinaryTreeNode *root,map<BinaryTreeNode *, BinaryTreeNode *> &mpp,int start){
    queue<BinaryTreeNode *> q;
    q.push(root);
    BinaryTreeNode *res = nullptr;
    while (!q.empty())    {
        BinaryTreeNode *node = q.front();
        q.pop();
        if (node->val == start)
            res = node;
        if (node->left)        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int timeToBurnTree(BinaryTreeNode *root, int start){
    map<BinaryTreeNode *, BinaryTreeNode *> mpp;
    BinaryTreeNode *target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

int main(){
    BinaryTreeNode *root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->left->right->left = new BinaryTreeNode(6);
    root->left->right->right = new BinaryTreeNode(7);
    int start = 5;
    cout << "Minimum time to burn the entire tree: "<< timeToBurnTree(root, start) << endl;
    return 0;
}