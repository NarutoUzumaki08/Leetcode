#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int n = s.size();
        int cnt = 1, ans = INT_MIN;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] - s[i - 1])
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        return ans;
    }
};