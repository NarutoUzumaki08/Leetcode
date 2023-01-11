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
    unordered_map<pi, ll> dp;
    ll solve(vi &a, ll target, ll n, ll i)
    {
        if (i == n)
        {
            if (target == 0)
                return 1;
            return 0;
        }
        if (dp.find({i, target}) != dp.end())
            return dp[{i, target}];
        ll res1 = solve(a, target + a[i], n, i + 1);
        ll res2 = solve(a, target - a[i], n, i + 1);
        return dp[{i, target}] = res1 + res2;
    }
    int findTargetSumWays(vector<int> &a, int target)
    {
        // memset(dp, -1, sizeof dp);
        ll n = a.size();
        ll ans = solve(a, target, n, 0);
        return ans;
    }
};