#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums, int len, int k)
    {
        int sum = 0, n = nums.size();
        for (int i = 0; i < len; i++)
            sum += nums[i];
        if (sum >= k)
            return true;
        int i = 0;
        for (int j = len; j < n; j++)
        {
            sum -= nums[i++];
            sum += nums[j];
            if (sum >= k)
                return true;
        }
        return false;
    }
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 1, r = n, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(nums, mid, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};