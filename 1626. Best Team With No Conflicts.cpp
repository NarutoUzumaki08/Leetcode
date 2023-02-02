#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<pair<int, int>> v;
    vector<int> scores, ages;
    vector<vector<int>> dp;
    int solve(int i, int prevIndex)
    {
        if (i == n)
            return 0;
        int ans = 0, res = 0;
        if (dp[i][prevIndex + 1] != -1)
            return dp[i][prevIndex + 1];
        if (prevIndex == -1)
        {
            res = v[i].second + solve(i + 1, i);
            ans = max(solve(i + 1, prevIndex), res);
            return ans;
        }
        if (v[i].second >= v[prevIndex].second)
            res = v[i].second + solve(i + 1, i);
        ans = max(solve(i + 1, prevIndex), res);
        return dp[i][prevIndex + 1] = ans;
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        this->scores = scores, this->ages = ages;
        n = scores.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
            v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        return solve(0, -1);
    }
};