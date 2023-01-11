#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {1, 1}, {1, -1}};
    vector<vector<int>> dp;
    int n;
    bool check(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int solve(vector<vector<int>> &grid, int i, int j)
    {
        if (!check(i, j))
            return INT_MAX;
        if (i == n - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for (auto d : dir)
        {
            int x = i + d.first, y = j + d.second;
            res = min(res, solve(grid, x, y));
        }
        return dp[i][j] = res + grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
            res = min(res, solve(grid, 0, j));
        return res;
    }
};