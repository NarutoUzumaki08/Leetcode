#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        multiset<int> m;
        int n = buildings.size();
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; i++)
        {
            edges.push_back({buildings[i][0], -buildings[i][2]});
            edges.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(edges.begin(), edges.end());
        m.insert(0);
        vector<vector<int>> skyline;
        int prev = 0, curr = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i].first, currHeight = edges[i].second;
            if (currHeight < 0)
                m.insert(-currHeight);
            else
                m.erase(m.find(currHeight));
            curr = *m.rbegin();
            if (curr != prev)
            {
                skyline.push_back({x, curr});
                prev = curr;
            }
        }
        return skyline;
    }
};