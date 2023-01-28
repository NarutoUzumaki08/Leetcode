#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct Node
    {
        int city, cost, stops;
        Node(int city, int cost, int stops)
        {
            this->city = city;
            this->cost = cost;
            this->stops = stops;
        }
    };
    static bool comp(Node a, Node b)
    {
        return a.cost > b.cost;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dest, int k)
    {
        vector<int> stops(n + 1, INT_MAX), dist(n + 1, INT_MAX);
        priority_queue<Node, vector<Node>, decltype(&comp)> pq(&comp);
        vector<pair<int, int>> adj[n];
        for (auto flight : flights)
        {
            int u = flight[0], v = flight[1], cost = flight[2];
            adj[u].push_back({v, cost});
        }
        while (!pq.empty())
        {
            Node curr = pq.top();
            pq.pop();
            if (curr.stops > stops[curr.city] || curr.stops > k + 1)
                continue;
            stops[curr.city] = curr.stops;
            if (curr.city == dest)
                return curr.cost;
            for (auto &[ngb, price] : adj[curr.city])
                pq.push(Node(ngb, price + curr.cost, curr.stops + 1));
        }
        return -1;
    }
};