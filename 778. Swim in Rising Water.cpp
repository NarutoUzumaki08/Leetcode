#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> grid;
    int n;
    vector<vector<int>> vis;
    bool inGrid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    bool dfs(int i, int j, int waterHeight)
    {
        vis[i][j] = 1;
        for (auto d : dir)
        {
            int x = i + d.first, y = j + d.second;
            if (inGrid(x, y) && !vis[x][y] && grid[x][y] <= waterHeight)
            {
                if (x == n - 1 && y == n - 1)
                    return true;
                else if (dfs(x, y, waterHeight))
                    return true;
            }
        }
        return false;
    }
    bool isPossible(int waterHeight)
    {
        vis = vector<vector<int>>(n, vector<int>(n, 0));
        return dfs(0, 0, waterHeight);
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        this->grid = grid;
        n = grid.size();
        int l = 0, r = n * n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (isPossible(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};