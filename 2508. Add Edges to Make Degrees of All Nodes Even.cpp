#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check_possibility(int a, int b, vector<set<int>> &adj, int c, int d)
    {
        if (adj[a].count(b) == 0 && adj[c].count(d) == 0)
            return true;
    }
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        vector<set<int>> adj(n + 1);
        int tot = edges.size();
        for (auto e : edges)
        {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        vector<int> odd_degree;
        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() % 2)
                odd_degree.push_back(i);
        }
        int cnt = odd_degree.size();
        if (cnt == 0)
            return true;
        if (cnt == 2)
        {
            int node1 = odd_degree[0], node2 = odd_degree[1];
            for (int i = 1; i <= n; i++)
            {
                if (adj[node1].count(i) == 0 && adj[node2].count(i) == 0)
                    return true;
            }
        }
        if (cnt == 4)
        {
            int a = odd_degree[0], b = odd_degree[1], c = odd_degree[2], d = odd_degree[3];
            if (check_possibility(a, b, adj, c, d))
                return true;
            if (check_possibility(a, c, adj, b, d))
                return true;
            if (check_possibility(a, d, adj, b, c))
                return true;
        }
        return false;
    }
};