#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> paths;
    int n;
    void dfs(int node, vector<int> &path, vector<vector<int>> &graph)
    {
        path.push_back(node);
        if (node == n - 1)
            paths.push_back(path);
        else
        {
            for (auto e : graph[node])
                dfs(e, path,graph);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> path;
        n = graph.size();
        dfs(0, path,graph);
        return paths;
    }
};