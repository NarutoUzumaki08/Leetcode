#include <bits/stdc++.h>
#define ll long long;
using namespace std;
class Solution
{
public:
    int dp[51][101][51];
    int mod = 1e9 + 7;
    int solve(int n, int m, int k, int i, int prevMax)
    {
        if (i == n || k <= 0)
            return k == 0 ? 1 : 0;
        if (dp[i][prevMax][k] != -1)
            return dp[i][prevMax][k];
        long long ans = 0;
        for (int curr = 1; curr <= m; curr++)
        {
            if (curr > prevMax)
                ans += solve(n, m, k - 1, i + 1, curr);
            else
                ans += solve(n, m, k, i + 1, prevMax);
        }
        return dp[i][prevMax][k] = ans % mod;
    }
    int numOfArrays(int n, int m, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, m, k, 0, 0);
    }
};