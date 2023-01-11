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
    TreeNode *addOneRow(TreeNode *root, int value, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(value);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int n = q.size();
            level++;
            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (depth - 1 != level)
                {
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
                else
                {
                    TreeNode *leftnewRoot = new TreeNode(value);
                    TreeNode *rightnewRoot = new TreeNode(value);
                    leftnewRoot->left = curr->left;
                    rightnewRoot->right = curr->right;
                    curr->left = leftnewRoot;
                    curr->right = rightnewRoot;
                }
            }
        }
        return root;
    }
};