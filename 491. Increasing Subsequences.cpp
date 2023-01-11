#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    set<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> &curr, int i)
    {
        if (i == n)
        {
            if (curr.size() >= 2)
            {
                if (is_sorted(curr.begin(), curr.end()))
                    ans.insert(curr);
            }
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, curr, i + 1);
        curr.pop_back();
        solve(nums, curr, i + 1);
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        n = nums.size();
        vector<int> curr;
        solve(nums, curr, 0);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};