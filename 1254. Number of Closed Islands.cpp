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
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> vis;
    int n, m;
    bool check(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (!check(i, j) || vis[i][j] || grid[i][j] == 0)
            return 0;
        vis[i][j] = 1;
        int ans = 1;
        for (auto d : dir)
        {
            int x = i + d.first, y = j + d.second;
            ans += dfs(x, y, grid);
        }
        return ans;
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        vis.resize(n, vector<int>(m, 0));
        int openOnes = 0, ones = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    openOnes += dfs(i, j, grid);
                ones += grid[i][j];
            }
        }
        return ones - openOnes;
    }
};