#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        bool col0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 0)
                col0 = 1;
            for (int j = 1; j < m; j++)
            {
                if (grid[i][j] == 0)
                    grid[i][0] = grid[0][j] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 1; j--)
            {
                if (grid[i][0] == 0 || grid[0][j] == 0)
                    grid[i][j] = 0;
            }
            if (col0)
                grid[i][0] = 0;
        }
    }
};