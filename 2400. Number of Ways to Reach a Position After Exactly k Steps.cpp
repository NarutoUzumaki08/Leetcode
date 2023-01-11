#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    ll mod = 1e9 + 7;
    int dp[3020][1005];
    ll solve(int currPos, int endPos, int k)
    {
        if (currPos == endPos && k == 0)
            return 1;
        if (k < 0)
            return 0;
        if (dp[currPos + 1000][k] != -1)
            return dp[currPos + 1000][k];
        int ans = solve(currPos + 1, endPos, k - 1) % mod;
        if ((k - 1) >= (endPos - currPos + 1))
            ans += solve(currPos - 1, endPos, k - 1) % mod;
        return dp[currPos + 1000][k] = ans % mod;   
    }
    int numberOfWays(int startPos, int endPos, int k)
    {
        memset(dp, -1, sizeof(dp));
        if (abs(startPos - endPos) > k)
            return 0;
        return solve(startPos, endPos, k);
    }
};