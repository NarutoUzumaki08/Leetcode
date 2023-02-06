#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    queue<pair<int, int>> q;
    vector<vector<int>> grid;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n;
    bool check(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    void dfs(int i, int j)
    {
        grid[i][j] = 2;
        q.push({i, j});
        for (auto d : dir)
        {
            int x = i + d.first, y = j + d.second;
            if (check(x, y) && grid[x][y] == 1)
                dfs(x, y);
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        this->grid = grid;
        n = grid.size();
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    dfs(i, j);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        int curr = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                for (auto d : dir)
                {
                    int x = i + d.first, y = j + d.second;
                    if (check(x, y))
                    {
                        if (grid[x][y] == 1)
                            return curr;
                        if (grid[x][y] == 0)
                        {
                            grid[x][y] = 2;
                            q.push({x, y});
                        }
                    }
                }
            }
            curr++;
        }
        return curr;
    }
};