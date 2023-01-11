/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int target, vector<int> &curr, vector<int> &arr, int idx)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (target < 0)
            return;
        for (int i = idx; i < arr.size(); i++)
        {
            curr.push_back(arr[i]);
            solve(target - arr[i], curr, arr, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> curr;
        solve(target, curr, arr, 0);
        return ans;
    }
};
// @lc code=end
