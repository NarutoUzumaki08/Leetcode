#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> bit(32);
        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[j] & (1 << i))
                    bit[i].push_back(j);
            }
        }
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++)
        {
            int res = 1;
            for (int j = 0; j < 32; j++)
            {
                int idx = lower_bound(bit[j].begin(), bit[j].end(), i) - bit[j].begin();
                if (idx == bit[j].size())
                    continue;
                res = max(res, bit[j][idx] - i + 1);
            }
            ans[i] = res;
        }
        return ans;
    }
};