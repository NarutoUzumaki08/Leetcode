#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int mod = 1e9 + 7;
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<int> pows(n);
        pows[0] = 1;
        for (int i = 1; i < n; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
            {
                ans = (ans + pows[r - l]) % mod;
                ++l;
            }
            else
                --r;
        }
        return ans;
    }
};
