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
class prop
{
public:
    bool isBst;
    int minVal, maxVal, sum;
    prop()
    {
        isBst = false;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        sum = 0;
    }
};
class Solution
{
public:
    int ans = 0;
    prop calSum(TreeNode *root)
    {
        if (root == NULL)
            return prop();
        prop curr;  
        prop currLeft = calSum(root->left);
        prop currRight = calSum(root->right);
        if (currLeft.isBst && currRight.isBst && currLeft.maxVal < root->val && currRight.minVal > root->val)
        {
            curr.isBst = true;
            curr.minVal = min(currLeft.minVal, root->val);
            curr.maxVal = max(currRight.maxVal, root->val);
            curr.sum = currLeft.sum + currRight.sum + root->val;
        }
        else
        {
            curr.isBst = false;
            curr.sum = 0;
        }
        ans = max(ans, curr.sum);
        return curr;
    }
    int maxSumBST(TreeNode *root)
    {
        ans = 0;
        calSum(root);
        return ans;
    }
};