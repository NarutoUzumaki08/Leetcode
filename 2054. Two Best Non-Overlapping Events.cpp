#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<int> startTime;
    int dp[100005][2];
    vector<vector<int>> event;
    int ans = 0;
    int solve(int i, int state)
    {
        if (i >= n)
            return 0;
        vector<int> res(4);
        int j = upper_bound(startTime.begin(), startTime.end(), event[i][1]) - startTime.begin();
        if (dp[i][state] != -1)
            return dp[i][state];
        if (!state)
        {
            res[0] = event[i][2] + solve(j, 1);
            res[1] = solve(i + 1, 0);
            return dp[i][state] = max(res[0], res[1]);
        }
        res[2] = event[i][2], res[3] = solve(i + 1, 1);
        return dp[i][state] = max(res[2], res[3]);
    }
    int maxTwoEvents(vector<vector<int>> &events)
    {
        n = events.size();
        sort(events.begin(), events.end());
        event = events;
        for (auto e : events)
        {
            int currStartTime = e[0], endTime = e[1], value = e[2];
            startTime.push_back(currStartTime);
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};