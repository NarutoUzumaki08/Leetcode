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
    map<int, int> height, depth;
    map<int, vector<pair<int, int>>> cousins;
    int dfs(TreeNode *root, int level)
    {
        if (!root)
            return -1;
        depth[root->val] = level;
        int leftHeight = dfs(root->left, level + 1);
        int rightHeight = dfs(root->right, level + 1);
        height[root->val] = max(leftHeight, rightHeight) + 1;
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        int h = dfs(root, 0);
        for (auto [val, d] : depth)
        {
            cousins[d].push_back({height[val], val});
            sort(cousins[d].begin(), cousins[d].end(), greater<pair<int, int>>());
            if (cousins[d].size() > 2)
                cousins[d].pop_back();
        }
        vector<int> ans;
        for (auto &q : queries)
        {
            int d = depth[q];
            if (cousins[d].size() == 1)
                ans.push_back(d - 1);
            else if (cousins[d][0].second == q)
                ans.push_back(cousins[d][1].first + d);
            else
                ans.push_back(h);
        }
        return ans;
        // return ans;
    }
};