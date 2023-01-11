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
    long long ans = 0;
    void solve(map<long, long> mp, long long prevSum, int targetSum, TreeNode *root)
    {
        if (!root)
            return;
        long long currSum = prevSum + root->val;
        if (mp.find(currSum - targetSum) != mp.end())
            ans += mp[currSum - targetSum];
        mp[currSum]++;
        solve(mp, currSum, targetSum, root->left);
        solve(mp, currSum, targetSum, root->right);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        map<long, long> mp;
        mp[0] = 1;
        solve(mp, 0ll, targetSum, root);
        return ans;
    }
};