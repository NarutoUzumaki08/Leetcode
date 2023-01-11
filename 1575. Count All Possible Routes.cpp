#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(int fuel, vector<int> &location, int currCity, int endCity)
    {
        if (dp[currCity][fuel] != -1)
            return dp[currCity][fuel];
        int ans = 0;
        if (currCity == endCity)
            ans++;
        for (int nextCity = 0; nextCity < n; nextCity++)
        {
            int fuelLeft = fuel - abs(location[currCity] - location[nextCity]);
            if (nextCity == currCity || fuelLeft < 0)
                continue;
            ans += solve(fuelLeft, location, nextCity, endCity) % MOD;
            ans %= MOD;
        }
        return dp[currCity][fuel] = ans % MOD;
    }
    int countRoutes(vector<int> &location, int start, int finish, int fuel)
    {
        n = location.size();
        dp = vector<vector<int>>(n, vector<int>(fuel + 1, -1));
        return solve(fuel, location, start, finish);
    }
};