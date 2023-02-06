#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[2005];
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (auto e : prerequisites)
            adj[e[1]].push_back(e[0]);
        vector<int> topo = topoSort(numCourses, adj);
        return topo.size() == numCourses;
    }
};