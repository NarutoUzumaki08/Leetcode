#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<long long>> dp;
    long long n, sum, mod = 1e9 + 7;
    long long solve(int i, int curr, vector<int> &nums, int k)
    {
        if (i == n)
            return curr < k ? 1 : 0;
        if (curr > k)
            return 0;
        if (dp[i][curr] != -1)
            return dp[i][curr];
        long long ans1 = solve(i + 1, curr, nums, k) % mod;
        long long ans2 = solve(i + 1, curr + nums[i], nums, k) % mod;
        return dp[i][curr] = (ans1 + ans2) % mod;
    }
    int countPartitions(vector<int> &nums, int k)
    {
        n = nums.size();
        for (auto x : nums)
            sum += x;
        if (sum < 2 * k)
            return 0;
        dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1, -1));
        long long subset_sum_less_than_k = solve(0, 0, nums, k);
        subset_sum_less_than_k--;
        long long total_subsets = 2;
        for (long long i = 2; i <= n; i++)
            total_subsets = (total_subsets * 2) % mod;
        total_subsets -= 2;
        long long ans = ((total_subsets - ((2 * subset_sum_less_than_k) % mod)) + mod) % mod;
        return ans;
    }
};