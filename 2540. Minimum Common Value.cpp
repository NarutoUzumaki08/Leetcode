#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp;
        for (auto num : nums1)
            mp[num]++;
        for (auto num : nums2)
        {
            if (mp.find(num) != mp.end())
                return num;
        }
        return -1;
    }
};

