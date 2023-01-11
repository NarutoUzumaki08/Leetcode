#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef int ll;
using namespace std;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vp;
#define f(i, n) for (ll i = 0; i < n; i++)
#define rf(i, n) for (ll i = n - 1; i >= 0; i--)
#define F first
#define S second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define Map map<ll, ll>
#define Set set<ll>
#define rep(i, j, k) for (int i = j; i < k; i++)
#define inf 1000000000000000005
ll MOD = 1000000000 + 7;
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
class Solution
{
public:
    bool isValid(ll n, ll m, ll i, ll j)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }
    vp dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++)
        {

            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &h, vector<vector<bool>> &vis, int i, int j)
    {
        int m = h.size();
        int n = h[0].size();
        vis[i][j] = true;
        for (auto d : dir)
        {
            ll x = i + d.F, y = j + d.S;
            if (isValid(m, n, x, y) && h[x][y] >= h[i][j] && !vis[x][y])
                dfs(h, vis, x, y);
        }
    }
};