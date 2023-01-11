#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[100000], vis, res, level, count;
    void dfs(int u)
    {
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            level[v] = level[u] + 1;
            dfs(v);
            count[u] += count[v];
        }
    }
    void sum_of_distances(int u, int n)
    {
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            res[v] = res[u] - count[v] + n - count[v];
            sum_of_distances(v, n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vis = vector<int>(n, 0), res = vector<int>(n, 0);
        level = vector<int>(n, 0), count = vector<int>(n, 1);
        dfs(0);
        res[0] = accumulate(level.begin(), level.end(), 0);
        vis = vector<int>(n, 0);
        sum_of_distances(0, n);
        return res;
    }
};