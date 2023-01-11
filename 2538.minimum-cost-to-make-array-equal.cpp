/*
 * @lc app=leetcode id=2538 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    ll n;
    ll f(vector<int> &nums, vector<int> &cost, ll x)
    {
        ll res = 0;
        for (ll i = 0; i < n; i++)
            res += 1L * abs(nums[i] - x) * cost[i];
        return res;
    }
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        ll l = 1, r = 1e6, res = f(nums, cost, 1), n = nums.size();
        while (l < r)
        {
            ll mid = (l + r) / 2;
            ll y1 = f(nums, cost, mid), y2 = f(nums, cost, mid + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = mid;
            else
                l = mid + 1;
        }
        return res;
    }
};
// @lc code=end
