#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class Solution
{
public:
    bool check(vector<int> nums, ll val, ll n)
    {
        ll ans = 0, carry = 0;
        for (ll i = n - 1; i >= 1; i--)
        {
            nums[i] += carry;
            if (nums[i] <= val)
            {
                carry = 0;
                continue;
            }
            carry = nums[i] - val;
            // nums[i]-=val;
        }
        if (nums[0] + carry <= val)
            return true;
        return false;
    }
    int minimizeArrayValue(vector<int> &nums)
    {
        ll n = nums.size();
        ll l = 0, r = *max_element(nums.begin(), nums.end()), ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(nums, mid, n))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};