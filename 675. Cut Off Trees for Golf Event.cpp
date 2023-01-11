#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    int bfs(int si, int sj, int ti, int tj, vector<vector<int>> &forest)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[si][sj] = 1;
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({si, sj});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if (i == ti && j == tj)
                return dist[i][j];
            for (auto d : dir)
            {
                int ni = i + d.first, nj = j + d.second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && forest[ni][nj] != 0 && vis[ni][nj] == 0)
                {
                    vis[ni][nj] = 1;
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>> &forest)
    {
        n = forest.size(), m = forest[0].size();
        vector<vector<int>> positions;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (forest[i][j] > 1)
                    positions.push_back({forest[i][j], i, j});
            }
        }
        sort(positions.begin(), positions.end());
        int si = 0, sj = 0;
        int ans = 0;
        for (auto p : positions)
        {
            int ti = p[1], tj = p[2];
            int d = bfs(si, sj, ti, tj, forest);
            if (d == -1)
                return -1;
            ans += d;
            forest[ti][tj] = 1;
            si = ti, sj = tj;
        }
        return ans;
    }
};