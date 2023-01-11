#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dp;
    int n;
    int solve(vector<vector<int>> &range, int i, vector<int> &startTime)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int j = lower_bound(startTime.begin(), startTime.end(), range[i][1]) - startTime.begin();
        int take = range[i][2] + solve(range, j, startTime), notTake = solve(range, i + 1, startTime);
        int ans = max(take, notTake);
        return ans;
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = profit.size();
        dp.resize(n + 1, -1);
        vector<vector<int>> range(n);
        for (int i = 0; i < n; i++)
            range[i] = {startTime[i], endTime[i], profit[i]};
        sort(range.begin(), range.end());
        sort(startTime.begin(), startTime.end());
        return solve(range, 0, startTime);
    }
};