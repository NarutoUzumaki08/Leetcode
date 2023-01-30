#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        string ans = "", curr = "";
        int n = s.size(), cnt = 0;
        bool skip = 0;
        for (int i = 0; i < n; i++)
        {
            cnt++;
            curr += s[i];
            if (cnt == k && !skip)
            {
                reverse(curr.begin(), curr.end());
                ans += curr, curr = "", skip ^= 1, cnt = 0;
            }
            else if (cnt == k && skip)
                ans += curr, curr = "", skip ^= 1, cnt = 0;
        }
        if (!skip)
            reverse(curr.begin(), curr.end());
        if (cnt)
            ans += curr;
        return ans;
    }
};