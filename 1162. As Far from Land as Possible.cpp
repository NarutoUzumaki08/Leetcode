#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(int i,int j,int n)
    {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    int maxDistance(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int n = grid.size();
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j, 0});
            }
        }
        int ans = INT_MIN;
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            int i = v[0], j = v[1], currDistance = v[2];
            for (auto d : dir)
            {
                int x = i + d.first, y = j + d.second;
                if (check(x, y, n) && grid[x][y] == 0)
                {
                    grid[x][y] = 1;
                    q.push({x, y, currDistance + 1});
                    ans = max(ans, currDistance + 1);
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};