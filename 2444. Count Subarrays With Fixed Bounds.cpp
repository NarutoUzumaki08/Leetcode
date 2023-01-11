#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        ll jmin = -1, jmax = -1, j = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                jmin = -1, jmax = -1, j = i + 1;
                continue;
            }
            if (minK == nums[i])
                jmin = i;
            if (maxK == nums[i])
                jmax = i;
            ans += min(0ll, min(jmin, jmax) - j + 1);
        }
        return ans;
    }
};

// 2 1 1 3 5 7 2 3 1 5