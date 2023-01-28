#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int ans = 0;
        bool positive = true;
        string s = to_string(n);
        for (int i = 0; i < s.size(); i++)
        {
            if (positive)
                ans += s[i] - '0';
            else
                ans -= s[i] - '0';
            positive = !positive;
        }
        return ans;
    }

};