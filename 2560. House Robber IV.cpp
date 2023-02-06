#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nums;
    int n;
    bool check(int val, int k)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= val)
                count++, i++;
        }
        return count >= k;
    }
    int minCapability(vector<int> &nums, int k)
    {
        this->nums = nums;
        int l = 1, r = 1e9;
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid, k))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        return ans;
    }
};