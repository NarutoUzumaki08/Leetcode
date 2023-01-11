#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dp;
    int solve(int n)
    {
        if (n == 0 || n == 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        int ans = solve(n - 1) + solve(n - 2);
        return dp[n] = ans;
    }
    int climbStairs(int n)
    {
        dp = vector<int>(n + 1, -1);
        return solve(n);
    }
};