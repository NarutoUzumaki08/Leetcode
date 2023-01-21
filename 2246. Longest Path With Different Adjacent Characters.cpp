#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[100005];
    int n, ans = 1;
    void makeGraph(vector<int> &parent)
    {
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);
    }
    int dfs(int u, string &s)
    {
        if (adj[u].empty())
            return 1;
        int max1 = 0, max2 = 0;
        for (auto &v : adj[u])
        {
            if (s[u] == s[v])
                continue;
            int curr = dfs(v, s);
            ans = max(ans, curr);
            if (curr > max1)
                max2 = max1, max1 = curr;
            else
                max2 = max(max2, curr);
        }
        ans = max(ans, 1 + max1 + max2);
        return 1 + max1;
    }
    int longestPath(vector<int> &parent, string s)
    {
        n = parent.size();
        makeGraph(parent);
        dfs(0, s);
        return ans;
    }
};