#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

typedef vector<vector<char>> vvc;
#define f(i, n) for (ll i = 0; i < n; i++)
class Solution
{
public:
    vector<pair<ll, ll>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vvc &a, vvi &vis, ll i, ll j)
    {
        ll n = a.size(), m = a[0].size();
        if (i >= n || j >= m || i < 0 || j < 0 || a[i][j] == '0' || vis[i][j])
            return;
        vis[i][j] = 1;
        for (auto d : dir)
            dfs(a, vis, i + d.first, j + d.second);
    }
    int numIslands(vector<vector<char>> &a)
    {
        ll n = a.size(), m = a[0].size();
        vvi vis(n + 1, vi(m + 1, 0));
        ll ans = 0;
        f(i, n)
        {
            f(j, m)
            {
                if (a[i][j] == '1' && !vis[i][j])
                {
                    dfs(a, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};