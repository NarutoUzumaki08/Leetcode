#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'X' || grid[i][j] == 'Y')
            return;
        grid[i][j] = 'Y';
        for (auto d : dir)
        {
            int x = i + d.first;
            int y = j + d.second;
            dfs(x, y, grid);
        }
    }
    void solve(vector<vector<char>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 'O')
                        dfs(i, j, grid);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'Y')
                    grid[i][j] = 'Z';
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'O')
                    dfs(i, j, grid);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'Y')
                    grid[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'Z')
                    grid[i][j] = 'O';
            }
        }
    }
};