#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
        {
            int sum = 0, curr = 0;
            for (int j = 0; j < n; j++)
            {
                if (sum + nums[j] <= queries[i])
                {
                    curr++;
                    sum += nums[j];
                    continue;
                }
                break;
            }
            ans[i] = curr;
        }
        return ans;
    }
};
// @lc code=end
