#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<vector<long long>> dp;
    int cost(string s)
    {
        int n = s.size(), ans = 0;
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                ans++;
            i++, j--;
        }
        return ans;
    }
    long long solve(string s, int i, int k)
    {
        if (i == n && k != 0)
            return INT_MAX;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k == 1)
        {
            string last = s.substr(i, n - i + 1);
            return cost(last);
        }

        long long ans = INT_MAX, curr_cost = 0;
        string curr_string = "";
        for (int j = i; j < n; j++)
        {
            curr_string += s[j];
            ans = min(ans, cost(curr_string) + solve(s, j + 1, k - 1));
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k)
    {
        n = s.size();
        dp = vector(n + 1, vector<long long>(k + 1, -1));
        return solve(s, 0, k);
    }
};