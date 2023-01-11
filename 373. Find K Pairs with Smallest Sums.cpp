#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b)
        { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
        for (int i = 0; i < n && i < k; i++)
            pq.push({i, 0});
        int j = 0;
        while (k-- && !pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            res.push_back({curr.first, curr.second});
            if (curr.second + 1 < m)
                pq.push({nums1[curr.first], nums2[curr.second + 1]});
        }
        return res;
    }
};