#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> grid;
    bool solve(int i, int j, bool canDo)
    {
        if (i == n - 1 && j == m - 1)
            return false;
        if (grid[i][j] == 0)
            return true;
        if (canDo)
        {
            bool ans1=solve(i+1,j,false);
        }
    }
    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        this->grid = grid;
    }
};