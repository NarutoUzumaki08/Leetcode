#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int count1 = 0, count2 = 0, n = nums.size();
        for (auto num : nums)
        {
            if (num == 0)
                continue;
            if (num > 0)
                count1++;
            else
                count2++;
        }

        return max(count1, count2);
    }
};