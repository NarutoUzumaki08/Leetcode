#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &prefix, int n, int target)
    {
    }
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(prefix, n, target))
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
};