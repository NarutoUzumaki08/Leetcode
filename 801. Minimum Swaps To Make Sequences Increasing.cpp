#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<vector<int>> dp;
    int minSteps(vector<int> &nums1, vector<int> &nums2, int i, bool swapped)
    {
        if (i >= n)
            return 0;
        if (dp[i][swapped] != -1)
            return dp[i][swapped];
        int ans = INT_MAX;
        int prev1 = nums1[i - 1], prev2 = nums2[i - 1];
        if (swapped)
            swap(prev1, prev2);
        // no swapping
        if (nums1[i] > prev1 && nums2[i] > prev2)
            ans = minSteps(nums1, nums2, i + 1, false);
        // swap
        if (nums1[i] > prev2 && nums2[i] > prev1)
            ans = min(ans, 1 + minSteps(nums1, nums2, i + 1, true));
        return dp[i][swapped] = ans;
    }
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        n = nums1.size();
        bool swapped=false;
        dp.resize(n+1, vector<int>(2, -1));
        return minSteps(nums1, nums2, 1, swapped);
    }
};
