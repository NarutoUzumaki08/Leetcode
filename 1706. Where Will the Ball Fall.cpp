#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i == n)
            return j + 1;
        if (grid[i][j] == 1)
        {
            if (isValid(i, j + 1) && grid[i][j + 1] == 1)
                return dfs(grid, i + 1, j + 1);
        }
        else
        {
            if (isValid(i, j - 1) && grid[i][j - 1] == -1)
                return dfs(grid, i + 1, j - 1);
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        vector<int> ans;
        for (int j = 0; j < m; j++)
            ans.push_back(dfs(grid, 0, j));
        return ans;
    }
};