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
    int maxChunksToSorted(vector<int> &a)
    {
        long long ans = 0, n = a.size(), sum1 = 0, sum2 = 0;
        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n; i++)
        {
            sum1 += a[i], sum2 += sorted[i];
            if (sum1 == sum2)
                ans++;
        }
        return ans;
    }
};

// class Solution {
//     public int maxChunksToSorted(int[] arr) {
//         int n = arr.length;
//         int[] maxOfLeft = new int[n];
//         int[] minOfRight = new int[n];

//         maxOfLeft[0] = arr[0];
//         for (int i = 1; i < n; i++) {
//             maxOfLeft[i] = Math.max(maxOfLeft[i-1], arr[i]);
//         }

//         minOfRight[n - 1] = arr[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             minOfRight[i] = Math.min(minOfRight[i + 1], arr[i]);
//         }

//         int res = 0;
//         for (int i = 0; i < n - 1; i++) {
//             if (maxOfLeft[i] <= minOfRight[i + 1]) res++;
//         }

//         return res + 1;
//     }
// }