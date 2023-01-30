#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        string curr = "";
        int cnt = 0;
        while (curr.size() <= b.size())
        {
            curr += a;
            cnt++;
            if (curr.find(b) != string::npos)
                return cnt;
        }
        curr += a;
        cnt++;
        if (curr.find(b) != string::npos)
            return cnt;
        return -1;
    }
};