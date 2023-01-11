#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bestClosingTime(string s)
    {
        int n = s.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = s[0] == 'N' ? 1 : 0, suffix[n - 1] = s[n - 1] == 'Y' ? 1 : 0;
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'N')
                cnt++;
            prefix[i] = cnt;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] == 'N')
                continue;
            suffix[i] = suffix[i + 1] + 1;
        }
        int res = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++)
        {
            int curr = prefix[i] + suffix[i];
            if (curr < res)
            {
                res = curr;
                idx = i;
            }
        }
        return idx;
    }
};