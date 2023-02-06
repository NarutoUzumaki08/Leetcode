#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        for (int i = n; i < 2 * n; i++)
        {
            int secondNum = nums[i] << 10;
            nums[i - n] |= secondNum;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            nums[2 * i + 1] = nums[i] >> 10;
            nums[2 * i] = nums[i] & 1023;
        }
        return nums;
    }
};