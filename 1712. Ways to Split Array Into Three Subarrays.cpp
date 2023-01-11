#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> prefix;
    int n, mod = 1e9 + 7;
    int cntWays(int i, int low, int high)
    {
        if (low > high)
            return 0;
        auto it1 = lower_bound(prefix.begin(), prefix.begin() + i, low);
        auto it2 = upper_bound(prefix.begin(), prefix.begin() + i, high);
        return it2 - it1;
    }
    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        prefix.resize(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];
        int suffix = 0, ans = 0, totSum = prefix[n - 1];
        for (int i = n - 1; i >= 2; i--)
        {
            suffix += nums[i];
            ans += cntWays(i - 1, totSum - 2 * suffix, (totSum - suffix) / 2);
            ans %= mod;
        }
        return ans;
    }
};