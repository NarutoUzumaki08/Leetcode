#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
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
    vp dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool check(ll i, ll j, ll n, ll m)
    {
        return ((i >= 0 && i < n) && (j >= 0 && j < m));
    }
    ll dfs(vector<vector<int>> &a, ll i, ll j, vvi &dp, ll n, ll m)
    {
        ll ans = 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (auto d : dir)
        {
            ll x = i + d.F, y = j + d.S;
            if (check(x, y, n, m) && a[i][j] < a[x][y])
                ans = (ans + dfs(a, x, y, dp, n, m)) % MOD;
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>> &a)
    {
        ll n, m;
        n = a.size(), m = a[0].size();
        vvi dp(n, vi(m, -1));
        ll ans = 0;
        f(i, n)
        {
            f(j, m)
            {
                ans = (ans + dfs(a, i, j, dp, n, m)) % MOD;
            }
        }
        return ans;
    }
};