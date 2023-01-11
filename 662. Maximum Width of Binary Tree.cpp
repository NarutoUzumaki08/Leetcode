#include <bits/stdc++.h>
// #define int long long int
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
    typedef long long ll;
    int level = 0;
    map<ll, pair<ll, ll>> mp;
    void solve(TreeNode *root, ll level, ll i)
    {
        if (!root)
            return;
        if (mp.find(level) == mp.end())
            mp[level] = {LONG_MAX, LONG_MIN};
        ll mn = min(mp[level].first, i), mx = max(mp[level].second, i);
        mp[level] = {mn, mx};
        solve(root->left, level + 1, 2 * i + 1);
        solve(root->right, level + 1, 2 * i + 2);
    }
    int widthOfBinaryTree(TreeNode *root)
    {
        solve(root, 0, 0);
        ll ans = 0;
        for (auto x : mp)
            ans = max(ans, x.second.second - x.second.first + 1);
        return ans;
    }
};