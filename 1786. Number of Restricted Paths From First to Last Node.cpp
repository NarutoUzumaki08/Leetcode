#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> adj[1000005];
    vector<int> dp;
    const int mod = 1e9 + 7;
    vector<int> dist;
    vector<int> dijkstra(int source, int n)
    {
        dist = vector<int>(n, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for (auto v : adj[u])
            {
                if (dist[u] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[u] + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
    }
    int dfs(int u)
    {
        if (u == 0)
            return 1;
        if (dp[u] != -1)
            return dp[u];
        int ans = 0, parVal = dist[u];
        for (auto [v, w] : adj[u])
        {
            int childVal = dist[v];
            if (parVal < childVal)
                ans = (ans + dfs(v)) % mod;
        }
        return dp[u] = ans % mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        for (auto e : edges)
        {
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist = dijkstra(n - 1, n);
        dp = vector<int>(n, -1);
        return dfs(n - 1);
    }
};