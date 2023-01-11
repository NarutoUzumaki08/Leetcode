#include <bits/stdc++.h>
typedef long long ll;
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
    ll mod = 1e9 + 7, totalSum = 0, ans = 0;
    ll subtreeSum(TreeNode *root)
    {
        if (!root)
            return 0;
        ll curr = root->val + subtreeSum(root->left) + subtreeSum(root->right);
        ans = max(ans, curr * (totalSum - curr));
        return curr;
    }
    // void dfs(TreeNode *root)
    // {
    //     if (!root)
    //         return;
    //     ll sum = subtreeSum(root);
    //     ans = max(ans, (totalSum - sum) * sum);
    //     dfs(root->left);
    //     dfs(root->right);
    // }
    int maxProduct(TreeNode *root)
    {
        totalSum = subtreeSum(root);
        subtreeSum(root);
        // dfs(root);
        return ans % mod;
    }
};