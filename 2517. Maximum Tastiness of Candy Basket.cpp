#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &stalls, int mid, int k, int n)
    {
        int prev = stalls[0];
        k--;
        for (int i = 1; i < n; i++)
        {
            if (k == 0)
                return true;
            if (stalls[i] - prev >= mid)
            {
                k--;
                prev = stalls[i];
            }
        }
        if (k == 0)
            return true;
        return false;
    }
    int maximumTastiness(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        int l = 0, r = 1e9, ans = 0;
        sort(stalls.begin(), stalls.end());
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(stalls, mid, k, n))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};