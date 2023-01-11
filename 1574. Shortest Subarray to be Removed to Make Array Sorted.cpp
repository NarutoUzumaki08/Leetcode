#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void fillPrefix(vector<int> &prefix, vector<int> &a, int n)
    {
        prefix.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] >= prefix.back())
                prefix.push_back(a[i]);
            else
                break;
        }
    }
    void fillSuffix(vector<int> &suffix, vector<int> &a, int n)
    {
        suffix.push_back(a[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] <= suffix.back())
                suffix.push_back(a[i]);
            else
                break;
        }
        reverse(suffix.begin(), suffix.end());
    }
    int findLengthOfShortestSubarray(vector<int> &a)
    {
        if (is_sorted(a.begin(), a.end()))
            return 0;
        int n = a.size();
        vector<int> prefix, suffix;
        fillPrefix(prefix, a, n), fillSuffix(suffix, a, n);
        int n1 = prefix.size(), n2 = suffix.size();
        int ans = min(n - n1, n - n2);
        for (int i = 0; i < n1; i++)
        {
            auto it = lower_bound(suffix.begin(), suffix.end(), prefix[i]);
            if (it == suffix.end())
                continue;
            int curr = i + 1 + (suffix.end() - it + 1);
            ans = min(ans, n - curr);
        }
        return ans;
    }
};