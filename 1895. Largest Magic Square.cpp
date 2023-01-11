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
    ll giveMeAns(vvi &grid, ll x, ll y, ll s, ll n, ll m)
    {
        if ((x + s) > n || (y + s) > m)
            return 1;
        ll diagonal1 = 0, diagonal2 = 0;
        f(k, s)
        {
            diagonal1 += grid[x + k][y + k];
            diagonal2 += grid[x + s - k - 1][y + k];
        }
        if (diagonal1 != diagonal2)
            return 1;
        f(i, s)
        {
            ll row = 0;
            f(j, s)
                row += grid[x + i][y + j];
            ll col = 0;
            f(j, s)
                col += grid[x + j][y + i];
            if (row != diagonal1 || col != diagonal1)
                return 1;
        }
        return s;
    }
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        ll n = grid.size(), m = grid[0].size();
        ll ans = 1;
        f(i, n)
        {
            f(j, m)
            {
                f(k, min(n, m)+1)
                {
                    ll curr = giveMeAns(grid, i, j, k, n, m);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};