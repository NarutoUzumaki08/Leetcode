#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long n = nums.size(), ans = 0, count = 0;
        for (long long i = 0; i < n - 1; i++)
        {
            if (nums[i] == 0 && nums[i + 1] == 0)
                count++;
            else
            {
                if (nums[i] == 0)
                    count++;
                ans += (count * (count + 1)) / 2;
                count = 0;
            }
        }
        if (nums[n - 1] == 0)
            count++;
        ans += (count * (count + 1)) / 2;
        return ans;
    }
};