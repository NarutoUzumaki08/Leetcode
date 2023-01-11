#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<int> a;
    vector<vector<int>> dp;
    int recur(int i, int buy)
    {
        if (i >= n)
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int ans = 0;
        ans = max(ans, recur(i + 1, buy));
        if (buy)
            ans = max(ans, recur(i + 1, 0) - a[i]);
        else
            ans = max(ans, recur(i + 2, 1) + a[i]);
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int> &prices)
    {
        a = prices;
        n = a.size();
        dp = vector<vector<int>>(n + 5, vector<int>(2, -1));
        return recur(0, 1);
    }
};