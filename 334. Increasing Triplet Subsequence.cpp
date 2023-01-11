#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, INT_MAX), right(n, INT_MIN);
        int mn = nums[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = mn;
            mn = min(mn, nums[i]);
        }
        int mx = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = mx;
            mx = max(mx, nums[i]);
        }
        for (int i = 1; i < n - 1; i++)
            if (left[i] != INT_MAX && right[i] != INT_MAX && left[i] < nums[i] && nums[i] < right[i])
                return true;
        return false;
    }
};