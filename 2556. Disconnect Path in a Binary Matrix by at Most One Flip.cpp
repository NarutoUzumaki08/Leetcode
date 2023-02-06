#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> grid;
    int n, m;
    bool check(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}};
    bool dfs(int i, int j)
    {
        if (i == n - 1 && j == m - 1)
            return true;
        grid[i][j] = 0;
        for (auto d : dir)
        {
            int x = i + d.first, y = j + d.second;
            if (check(x, y) && grid[x][y] == 1)
            {
                if (dfs(x, y))
                    return true;
            }
        }
        return false;
    }
    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        this->grid = grid;
        if (!dfs(0, 0))
            return true;
        if (!dfs(0, 0))
            return true;
        return false;
    }
};