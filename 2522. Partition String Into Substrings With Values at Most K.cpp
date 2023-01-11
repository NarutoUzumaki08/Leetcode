#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumPartition(string s, int k)
    {
        int n = s.size(), ans = 0;
        string t = "";
        for (auto d : s)
        {
            t += d;
            long long currNumber = stoll(t);
            if (currNumber <= k)
                continue;
            t.pop_back();
            if (t.size() == 0)
                return -1;
            currNumber = stoll(t);
            if (currNumber <= k)
            {
                ans++;
                t = d;
            }
            else
                return -1;
        }
        if (t != "")
        {
            long long currNumber = stoll(t);
            if (currNumber <= k)
                ans++;
        }

        return ans;
    }
};