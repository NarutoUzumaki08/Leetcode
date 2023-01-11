#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<int> prefix_ones(n), suffix_zeros(n);
        prefix_ones[0] = s[0] == '1', suffix_zeros[n - 1] = s[n - 1] == '0';
        for (int i = 1; i < n; i++)
            prefix_ones[i] = prefix_ones[i - 1] + (s[i] == '1');
        for (int i = n - 2; i >= 0; i--)
            suffix_zeros[i] = suffix_zeros[i + 1] + (s[i] == '0');
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, suffix_zeros[i] + prefix_ones[i] - 1);
        return ans;
    }
};