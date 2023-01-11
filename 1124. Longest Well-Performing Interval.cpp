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
class Solution
{
public:
    int findLongestSub(string bin)
    {
        int n = bin.length(), i;

        // To store sum.
        int sum = 0;

        // To store first occurrence of each
        // sum value.
        unordered_map<int, int> prevSum;

        // To store maximum length.
        int maxlen = 0;

        // To store current substring length.
        int currlen;

        for (i = 0; i < n; i++)
        {

            // Add 1 if current character is 1
            // else subtract 1.
            if (bin[i] == '1')
                sum++;
            else
                sum--;

            // If sum is positive, then maximum
            // length substring is bin[0..i]
            if (sum > 0)
            {
                maxlen = i + 1;
            }

            // If sum is negative, then maximum
            // length substring is bin[j+1..i], where
            // sum of substring bin[0..j] is sum-1.
            else if (sum <= 0)
            {
                if (prevSum.find(sum - 1) != prevSum.end())
                {
                    currlen = i - prevSum[sum - 1];
                    maxlen = max(maxlen, currlen);
                }
            }

            // Make entry for this sum value in hash
            // table if this value is not present.
            if (prevSum.find(sum) == prevSum.end())
                prevSum[sum] = i;
        }

        return maxlen;
    }

    int longestWPI(vector<int> &hours)
    {
        ll n = hours.size();
        string s = "";
        f(i, n)
        {
            if (hours[i] > 8)
                s += '1';
            else
                s += '0';
        }
        return findLongestSub(s);
    }
};