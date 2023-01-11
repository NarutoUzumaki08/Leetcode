#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[100005];
    vector<int> vis;
    vector<bool> apple;
    int dfs(int u)
    {
        int childTime = 0;
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            childTime += dfs(v);
        }
        if (!childTime && !apple[u])
            return 0;
        return (childTime == 0 ? 0 : 2) + childTime;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vis = vector(n, 0);
        apple = hasApple;
        return dfs(0);
    }
};