#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dp;
    int n;
    int solve(int i, vector<int> &nums)
    {
        if (i > n)
            return false;
        if (i == n - 1)
            return true;
        if (dp[i] != -1)
            return dp[i];
        int ans = false;
        for (int j = 1; j <= nums[i]; j++)
        {
            ans = ans || solve(i + j, nums);
            if (ans)
                break;
        }
        return dp[i] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        n = nums.size();
        dp = vector<int>(n, -1);
        return solve(0, nums);
    }
};