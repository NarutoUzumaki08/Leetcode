#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> traversal;
    void preOrder(TreeNode *root)
    {
        if (!root)
            return;
        traversal.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        preOrder(root);
        return traversal;
    }
};