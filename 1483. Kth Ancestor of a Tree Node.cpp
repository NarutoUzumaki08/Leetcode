#include <bits/stdc++.h>
using namespace std;
class TreeAncestor
{
public:
    vector<vector<int>> dp;
    vector<int> adj[100000];
    int dfs(int node, int par)
    {
        dp[node][0] = par;
        for (int i = 1; i < 20; i++)
        {
            if (dp[node][i - 1] != -1)
                dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }
        for (auto &child : adj[node])
            if (child != par)
                dfs(child, node);
    }
    int getK(int node, int k)
    {
        if (k == 0)
            return node;
        if (k == 1)
            return dp[node][0];
        int last = -1;
        for (int i = 0; i < 20; i++)
        {
            if (k & (1 << i))
                last = i;
        }
        if (last == -1 || dp[node][last] == -1)
            return -1;
        return getK(dp[node][last], k ^ (1 << last));
    }
    TreeAncestor(int n, vector<int> &parent)
    {
        dp = vector<vector<int>>(n, vector<int>(20, -1));
        for (int i = 0; i < n; i++)
        {
            if (parent[i] != -1)
                adj[parent[i]].push_back(i);
        }
        dfs(0, -1);
    }

    int getKthAncestor(int node, int k)
    {
        return getK(node, k);
    }
};
