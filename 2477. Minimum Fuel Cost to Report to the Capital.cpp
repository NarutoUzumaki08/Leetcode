#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    vector<ll> adj[100005];
    ll n;
    ll ans = 0;
    vector<ll> distance;
    void calculateDistance(ll u, ll parentNode, ll currDistance)
    {
        for (auto v : adj[u])
        {
            if (v != parentNode)
            {
                if (distance[v] == INT_MAX)
                    distance[v] = currDistance + 1;
                calculateDistance(v, u, currDistance + 1);
            }
        }
    }
    void dfs(ll u, ll parentNode, ll currSeats, ll seats)
    {
        if (u == 0)
            return;
        for (auto v : adj[u])
        {
            if (v != parentNode)
            {
                currSeats++;
                if (currSeats == seats)
                {
                    ans += distance[v] * seats;
                    currSeats = 0;
                }
                else
                    ans++;
                dfs(v, u, currSeats, seats);
            }
        }
    }
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        n = roads.size() + 1;
        for (auto e : roads)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<ll> indegree(n);
        for (int i = 0; i < n; i++)
            indegree[i] = adj[i].size();
        distance = vector<ll>(n, INT_MAX);
        distance[0] = 0;
        calculateDistance(0, -1, 0);
        for (int i = 0; i < n; i++)
            cout << distance[i] << " ";
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                dfs(i, -1, 0, seats);
        }
        return ans;
    }
};