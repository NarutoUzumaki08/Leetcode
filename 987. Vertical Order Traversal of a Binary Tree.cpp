#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vp;
#define f(i, n) for (ll i = 0; i < n; i++)
#define F first
#define S second
#define PB push_back
#define all(v) (v).begin(), (v).end()
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            int x = q.size();
            for (int i = 0; i < x; i++)
            {
                auto curr = q.front();
                int x = curr.S.first, y = curr.second.second;
                mp[y].push_back({x, curr.first->val});
                q.pop();
                if (curr.first->left)
                    q.push({curr.first->left, {x + 1, y - 1}});
                if (curr.first->right)
                    q.push({curr.first->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto x : mp)
        {
            sort(x.second.begin(), x.second.end());
            vector<int> temp;
            for (auto y : x.S)
                temp.PB(y.S);
        }
        return ans;
    }
};