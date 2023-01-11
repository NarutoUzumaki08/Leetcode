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
    int max_sum = INT_MIN;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = max(0, dfs(root->left)), r = max(0, dfs(root->right));
        int curr = root->val + l + r;
        max_sum = max(max_sum, curr);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return max_sum;
    }
};