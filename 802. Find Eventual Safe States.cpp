#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[100005], ans;
    bool dfs(int u, vector<int> adj[], vector<int> &vis)
    {
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                if (dfs(v, adj, vis))
                    return true;
            }
            else if (vis[v] == 1)
                return true;
        }
        vis[u] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto j : graph[i])
                adj[i].push_back(j);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis);
        }
        for (int i = 0; i < n; i++)
            if (vis[i] == 2)
                ans.push_back(i);
        return ans;
    }
};