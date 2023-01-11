#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    #define ll long long
    bool bfs(ll src, vector<ll> adj[], vector<ll> &vis, ll V, vector<ll> &colors)
    {
        colors[src] = 1;
        queue<pair<ll, ll>> q;
        q.push({src, 1});
        colors[src] = 1;
        vis[src] = 1;
        while (!q.empty())
        {
            ll par = q.front().first;
            ll color_of_parent = q.front().second;
            q.pop();
            for (auto child : adj[par])
            {
                if (!vis[child])
                {
                    vis[child] = 1;
                    ll color_of_child = color_of_parent == 1 ? 2 : 1;
                    colors[child] = color_of_child;
                    q.push({child, color_of_child});
                }
                else
                {
                    ll color_of_child = colors[child];
                    if (color_of_child == color_of_parent)
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(ll V, vector<ll> adj[])
    {
        vector<ll> colors(V + 1, 0);
        vector<ll> vis(V + 1);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (bfs(i, adj, vis, V, colors) == false)
                    return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<ll> adj[n + 1];
        for (auto d : dislikes)
        {
            ll u = d[0], v = d[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return isBipartite(n, adj);
    }
};