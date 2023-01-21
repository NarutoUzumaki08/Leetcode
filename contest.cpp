#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    long long countGood(vector<int> &nums, int k)
    {
        ll n = nums.size();
        map<ll, ll> mp;
        ll count = 0, ans = 0;
        for (int i = 0, j = 0; j < n; j++)
        {
            mp[nums[j]]++;
            count += (mp[nums[j]] - 1);
            while (count >= k)
            {
                ans += n - j;
                count -= mp[nums[i]] - 1;
                mp[nums[i]]--;
                i++;
            }
        }
        return ans;
    }
};

