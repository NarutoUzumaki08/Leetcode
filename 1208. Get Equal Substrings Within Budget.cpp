#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int currCost = 0, n = s.size();
        int i = 0;
        int len = 0;
        for (int j = 0; j < n; j++)
        {
            while (i < n && currCost > maxCost)
            {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            currCost += abs(s[j] - t[j]);
            len = max(len, j - i + 1);
        }
        return len;
    }
};