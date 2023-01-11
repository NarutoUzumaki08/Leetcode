#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        vector<int> pos;
        map<int, int> mp;
        for (auto x : nums)
        {
            if (x > 0)
                pos.push_back(x);
            else
                mp[x]++;
        }
        sort(pos.rbegin(), pos.rend());
        for (auto x : pos)
        {
            if (mp.find(-x) != mp.end())
                return x;
        }
        return -1;
    }
};