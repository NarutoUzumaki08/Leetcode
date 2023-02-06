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
    int maxLen = 0;
    int solve(TreeNode *root, int prevVal)
    {
        if (!root)
            return 0;
        int leftMax = solve(root->left, root->val), rightMax = solve(root->right, root->val);
        maxLen = max(maxLen, leftMax + rightMax);
        if (root->val == prevVal)
            return max(leftMax, rightMax) + 1;
        return 0;
    }
    int longestUnivaluePath(TreeNode *root)
    {
        solve(root, root->val);
        return maxLen;
    }
};