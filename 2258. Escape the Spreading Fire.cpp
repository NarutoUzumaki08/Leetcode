#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m, inf = 1e9;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> fire_time;
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    bool bfs(vector<vector<int>> &grid, int wait_time)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<vector<int>> q;
        q.push({0, 0, wait_time});
        vis[0][0] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int i = curr[0], j = curr[1], reach_time = curr[2];
            if (i == n - 1 && j == m - 1 && reach_time + 1 <= fire_time[n - 1][m - 1])
                return true;
            for (auto d : dir)
            {
                int x = i + d.first, y = j + d.second;
                if (!valid(x, y) || grid[x][y] == 2 || vis[x][y])
                    continue;
                if (reach_time + 1 >= fire_time[x][y])
                    continue;
                vis[x][y] = true;
                q.push({x, y, reach_time + 1});
            }
        }
        return false;
    }
    int BinarySearchOnAnswer(vector<vector<int>> &grid)
    {
        int l = 0, r = 1e9, max_wait = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (bfs(grid, mid))
            {
                max_wait = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return max_wait;
    }
    void calculate_fire_Time(vector<vector<int>> &grid)
    {
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                    fire_time[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            auto v = q.front();
            int i = v[0], j = v[1], t = v[2];
            q.pop();
            for (auto d : dir)
            {
                int x = i + d.first, y = j + d.second;
                if (!valid(x, y) || vis[x][y] || grid[x][y] == 2 || grid[x][y] == 1)
                    continue;
                vis[x][y] = 1;
                fire_time[x][y] = t + 1;
                q.push({x, y, t + 1});
            }
        }
    }
    int maximumMinutes(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        fire_time = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        calculate_fire_Time(grid);
        return BinarySearchOnAnswer(grid);
    }
};

