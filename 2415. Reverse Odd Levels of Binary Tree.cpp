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
    TreeNode *constructTree(vector<int> &level, int i, int n)
    {
        if (i >= n)
            return NULL;
        TreeNode *root = new TreeNode(level[i]);
        root->left = constructTree(level, 2 * i + 1, n);
        root->right = constructTree(level, 2 * i + 2, n);
        return root;
    }
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int parity = 0;
        TreeNode *ansRoot;
        vector<vector<int>> v;
        while (!q.empty())
        {
            int x = q.size();
            vector<int> curr;
            while (x--)
            {
                TreeNode *currNode = q.front();
                q.pop();
                if (currNode->left)
                    q.push(currNode->left);
                if (currNode->right)
                    q.push(currNode->right);
                curr.push_back(currNode->val);
            }
            if (parity)
                reverse(curr.begin(), curr.end());
            v.push_back(curr);
            parity = !parity;
        }
        vector<int> level;
        for (auto x : v)
            for (auto y : x)
                level.push_back(y);
        int n = level.size();
        ansRoot = constructTree(level, 0, n);
        return ansRoot;
    }
};