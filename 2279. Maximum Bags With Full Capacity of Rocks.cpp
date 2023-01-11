#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = capacity.size();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {capacity[i] - rocks[i], capacity[i], rocks[i]};
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int curr_capacity = v[i][1], curr_rocks = v[i][2];
            v[i][2] += min(additionalRocks, curr_capacity - curr_rocks);
            additionalRocks -= min(additionalRocks, curr_capacity - curr_rocks);
            ans += curr_rocks == curr_capacity ? 1 : 0;
        }
        return ans;
    }
};