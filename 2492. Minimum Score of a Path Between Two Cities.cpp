#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> vis;
    int ans = INT_MAX;
    void dfs(int root, vector<pair<int, int>> adj[])
    {
        vis[root] = 1;
        for (auto &x : adj[root])
        {
            if (!vis[x.first])
            {
                ans = min(ans, x.second);
                dfs(x.first, adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n + 1];
        vis = vector<int>(n + 1, 0);
        for (auto &x : roads)
        {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dfs(1, adj);
        return ans;
    }
};