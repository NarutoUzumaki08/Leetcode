#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vp;
#define f(i, n) for (ll i = 0; i < n; i++)
#define PB push_back
#define rep(i, j, k) for (int i = j; i < k; i++)
class Solution
{
public:
    vector<vector<int>> dp;
    int n;
    int recur(vector<int> &job, int d, int i)
    {
        if (i == n && d == 0)
            return 0;
        if (i == n || d == 0)
            return INT_MAX;
        if (dp[i][d] != -1)
            return dp[i][d];
        int ans = INT_MAX, currMax = job[i];
        for (int j = i; j < n; j++)
        {
            currMax = max(currMax, job[j]);
            int aagekaAns = recur(job, d - 1, j + 1);
            if (aagekaAns != INT_MAX)
                ans = min(ans, currMax + aagekaAns);
        }
        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        n = jobDifficulty.size();
        dp.resize(n, vector<int>(d + 1, -1));
        return recur(jobDifficulty, d, 0);
    }
};
