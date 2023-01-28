#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getDistance(vector<int> &point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto point : points)
        {
            pq.push({getDistance(point), point[0], point[1]});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto [_, x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};