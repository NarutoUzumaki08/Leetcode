#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size(), m = strs[0].size(), ans = 0;
        for (int j = 0; j < m; j++)
        {
            vector<char> curr;
            for (int i = 0; i < n; i++)
                curr.push_back(strs[i][j]);
            if (!is_sorted(curr.begin(), curr.end()))
                ans++;
        }
        return ans;
    }
};