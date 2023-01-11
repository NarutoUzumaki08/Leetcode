/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size(), sum = 0, ans = INT_MAX;
        for (int i = 0, j = 0; j < n; j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
