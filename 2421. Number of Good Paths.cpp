#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rank, parent;
    int n;
    vector<int> adj[100005];
    void make_set()
    {
        rank = vector<int>(n);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    int find_parent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find_parent(parent[x]);
    }
    void union_set(int x, int y)
    {
        int px = find_parent(x), py = find_parent(y);
        if (px == py)
            return;
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        for (auto e : edges)
        {
            if (vals[e[1]] > vals[e[0]])
                swap(e[0], e[1]);
            adj[e[0]].push_back(e[1]);
        }
        int ans = 0;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[vals[i]].push_back(i);
        for (auto &[value, nodes] : mp)
        {
            for (auto u : nodes)
            {
                for (auto v : adj[u])
                    union_set(u, v);
            }
            map<int, int> group;
            for (auto u : nodes)
            {
                int p = find_parent(u);
                group[p]++;
            }
            ans += nodes.size();
            for (auto &[p, cnt] : group)
                ans += cnt * (cnt - 1) / 2;
        }
        return ans;
    }
};