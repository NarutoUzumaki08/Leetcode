#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0, neg = 1;
        for (auto &e : nums)
        {
            if (e > 0)
            {
                ans[pos] = e;
                pos += 2;
            }
            else
            {
                ans[neg] = e;
                neg += 2;
            }
        }
        return ans;
    }
};