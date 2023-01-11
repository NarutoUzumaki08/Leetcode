#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bits;
    bool check()
    {
        for (int i = 0; i < 31; i++)
        {
            if (bits[i] > 1)
                return true;
        }
        return false;
    }
    int longestNiceSubarray(vector<int> &nums)
    {
        bits = vector<int>(32, 0);
        int n = nums.size(), i = 0, res = 1;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 31; k++)
            {
                if (nums[j] & (1 << k))
                    bits[k]++;
            }
            while (check())
            {
                for (int k = 0; k < 31; k++)
                {
                    if (nums[i] & (1 << k))
                        bits[k]--;
                }
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};