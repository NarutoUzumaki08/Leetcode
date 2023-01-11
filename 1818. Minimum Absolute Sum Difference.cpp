#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        set<int> s(nums1.begin(), nums1.end());
        long long originalDiff = 0, maxDecrement = 0;
        for (int i = 0; i < n; i++)
        {
            long long currDiff = abs(nums1[i] - nums2[i]);
            auto it = s.lower_bound(nums2[i]);
            if (it != s.begin())
            {
                auto prev = it;
                prev--;
                maxDecrement = max(maxDecrement, currDiff - abs(*prev - nums2[i]));
            }
            if (it != s.end())
                maxDecrement = max(maxDecrement, currDiff - abs(*it - nums2[i]));
        }
        return (originalDiff - maxDecrement) % 1000000007;
    }
};