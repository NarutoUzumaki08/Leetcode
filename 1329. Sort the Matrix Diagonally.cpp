#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
#define f(i, n) for (ll i = 0; i < n; i++)
#define PB push_back
#define all(v) (v).begin(), (v).end()
class Solution
{
public:
    bool check(ll n, ll m, ll i, ll j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    vector<vector<int>> diagonalSort(vector<vector<int>> &grid)
    {
        ll n = grid.size(), m = grid[0].size();
        vvi vis(n, vi(m, 0));
        f(i, n)
        {
            f(j, m)
            {
                vi diagonal;
                if (vis[i][j] == 1)
                    continue;
                ll temp_i = i, temp_j = j;
                for (ll temp_i = i, temp_j = j; check(n, m, temp_i, temp_j); temp_i++, temp_j++)
                {
                    diagonal.PB(grid[temp_i][temp_j]);
                    vis[temp_i][temp_j] = 1;
                }
                sort(all(diagonal));
                for (ll temp_i = i, temp_j = j, k = 0; check(n, m, temp_i, temp_j); temp_i++, temp_j++, k++)
                    grid[temp_i][temp_j] = diagonal[k];
            }
        }
        return grid;
    }
};