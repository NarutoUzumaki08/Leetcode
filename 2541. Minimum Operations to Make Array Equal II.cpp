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
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        ll n = nums1.size();
        if (k == 0)
        {
            if (nums1 != nums2)
                return -1;
            return 0;
        }
        ll cnt_dec = 0, cnt_inc = 0;
        for (int i = 0; i < n; i++)
        {
            ll diff = nums1[i] - nums2[i];
            if (diff % k != 0)
                return -1;
            if (diff < 0)
                cnt_dec += ceil_div(abs(diff), k);
            else if (diff > 0)
                cnt_inc += ceil_div(abs(diff), k);
        }
        return cnt_inc == cnt_dec ? cnt_inc : -1;
    }
};

// 4 3 1 4

// 1 3 7 1