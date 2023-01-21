#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    vector<long long> adj[100005];
    vector<pair<long long, long long>> pathSum;
    vector<int> vis;
    vector<int> prices;
    vector<pair<long long, long long>> cost;
    long long dfs(long long u)
    {
        vis[u] = 1;
        long long maxSum = INT_MIN, minSum = INT_MAX;
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            long long currSum = dfs(v) + prices[v];
            maxSum = max(maxSum, currSum);
            minSum = min(minSum, currSum);
        }
        if (maxSum == INT_MIN)
            maxSum = minSum = 0;
        cost[u] = {maxSum, minSum};
        return maxSum;
    }

    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price)
    {
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        pathSum = vector<pair<long long, long long>>(n + 1, {0, 0});
        vis = vector<int>(n + 1, 0);
        prices = price;
        cost = vector<pair<long long, long long>>(n + 1, {0, 0});
        dfs(1);
        long long ans = 0;
        for (auto [mx, mn] : cost)
            ans = max(ans, mx - mn);
        return ans;
    }
};