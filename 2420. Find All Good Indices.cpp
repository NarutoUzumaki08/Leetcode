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
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> decreasing(n + 1, 1), increasing(n + 1, 1), required;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] >= nums[i])
                decreasing[i] = decreasing[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= nums[i + 1])
                increasing[i] = increasing[i + 1] + 1;
        }
        for (int i = k; i < n - k; i++)
        {
            if (decreasing[i - 1] >= k && increasing[i + 1] >= k)
                required.push_back(i);
        }
        return required;
    }
};