#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int start)
    {
        int n = words.size(), ans = INT_MAX;
        for (int i = 0, j = start; i < n; i++, j = (j + 1) % n)
        {
            if (words[j] == target)
            {
                int i1 = abs(start - j) % n, i2 = abs(n - i1) % n;
                ans = min(ans, min(i1, i2));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};