#include <bits/stdc++.h>
using namespace std;
#define Map unordered_map<int, int>
#define rep(i, j, k) for (int i = j; i < k; i++)
#define f(i, n) for (int i = 0; i < n; i++)
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        vector<Map> dp(n);
        int ans = 0;
        rep(i, 1, n)
        {
                f(j, i)
                {
                long long diff = (long long)nums[i] - nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += cnt + 1;
                ans += cnt;
            }
        }
        return ans;
    }
};