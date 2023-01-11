#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        int len = 1, curr = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == mx && nums[i + 1] == mx)
                curr++;
            else
            {
                len = max(len, curr);
                curr = 1;
            }
        }
        len = max(len, curr);
        return len;
    }
};