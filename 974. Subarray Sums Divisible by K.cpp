#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};