#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for (auto &[sum, v] : mp)
        {
            reverse(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
                ans.push_back(v[i]);
        }
        return ans;
    }
};