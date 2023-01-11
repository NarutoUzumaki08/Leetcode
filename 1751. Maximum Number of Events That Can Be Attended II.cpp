#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dp;
    vector<int> startTimes;
    int solve(vector<vector<int>> &events, int k, int i)
    {
        if (i >= events.size() || k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int currStart = events[i][0], currEnd = events[i][1], currVal = events[i][2];
        int ans = 0;
        int j = upper_bound(startTimes.begin(), startTimes.end(), currEnd) - startTimes.begin();
        ans = max(ans, currVal + solve(events, k - 1, j));
        ans = max(ans, solve(events, k, i + 1));
        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        sort(events.begin(), events.end());
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        for (auto e : events)
            startTimes.push_back(e[0]);
        return solve(events, k, 0);
    }
};