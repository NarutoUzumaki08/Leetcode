#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[100005];
    vector<int> vis, ans;
    string charLabels;
    vector<int> dfs(int u)
    {
        vector<int> parentCount(26);
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                vector<int> childCount = dfs(v);
                for (int i = 0; i < 26; i++)
                    parentCount[i] += childCount[i];
            }
        }
        parentCount[charLabels[u] - 'a']++;
        ans[u] = parentCount[charLabels[u] - 'a'];
        return parentCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        map<char, int> mp;
        vis = vector<int>(n, 0), ans = vector<int>(n, 0);
        charLabels = labels;
        dfs(0);
        return ans;
    }
};