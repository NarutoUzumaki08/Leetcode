#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        string prev = "1";
        if (n == 1)
            return prev;
        string curr = "";
        for (int i = 1; i < n; i++)
        {
            curr = "";
            int m = prev.size(), cnt = 1;
            for (int j = 1; j < m; j++)
            {
                if (prev[j] == prev[j - 1])
                    cnt++;
                else
                {
                    curr += to_string(cnt) + prev[j - 1];
                    cnt = 1;
                }
            }
            curr += to_string(cnt) + prev[m - 1];
            prev = curr;
        }
        return curr;
    }
};