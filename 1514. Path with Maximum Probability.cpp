#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dist;
    vector<pair<int, double>> adj[100005];
    void dijkstra(int source, int n)
    {
        dist = vector<int>(n, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        while (!pq.empty())
        {
            int u = pq.top().second;
            double d = pq.top().first;
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
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        for (auto &success : succProb)
            success = log(-success);
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0], v = edges[i][1], w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dijkstra(start, 0);
        double ans = exp(-dist[end]);
        return ans;
    }
};