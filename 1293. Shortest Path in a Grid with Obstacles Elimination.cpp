#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    bool outOfBounds(int x, int y)
    {
        return x < 0 || x >= n || y < 0 || y >= m;
    }
    struct node
    {
        int x, y, steps, k;
    };
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int steps = INT_MAX;
        queue<node> q;
        q.push({0, 0, 0, k});
        // vis[0][0] = grid[0][0] == 1 ? k - 1 : k;
        while (!q.empty())
        {
            int x = q.front().x, y = q.front().y, currSteps = q.front().steps, remObstacles = q.front().k;
            q.pop();
            if (outOfBounds(x, y))
                continue;
            if (x == n - 1 && y == m - 1)
                return currSteps;
            if (grid[x][y] == 1)
            {
                if (remObstacles > 0)
                    remObstacles--;
                else
                    continue;
            }
            if (vis[x][y] != -1 && vis[x][y] >= remObstacles)
                continue;
            vis[x][y] = remObstacles;
            for (auto d : dir)
            {
                int nx = x + d.first, ny = y + d.second;
                q.push({nx, ny, currSteps + 1, remObstacles});
            }
        }
        return -1;
    }
};