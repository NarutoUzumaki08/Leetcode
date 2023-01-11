#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        vector<int> vis(1e5 + 1);
        for (auto n : nums)
            vis[n] = 1;
        long long ans = 1;
        for (int i = 2; i <= 1e5; i++)
        {
            if (i > 316)
                break;
            if (vis[i] == 0)
                continue;
            long long cnt = 1, curr = i * i;
            if (curr > 1e5)
                continue;
            while (vis[curr])
            {
                vis[curr] = 0;
                cnt++;
                curr *= curr;
                if (curr > 1e5)
                    break;
            }
            ans = max(ans, cnt);
        }
        return ans == 1 ? -1 : ans;
    }
};