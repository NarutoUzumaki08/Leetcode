#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string breakPalindrome(string s)
    {
        int n = s.size();
        if (n == 1)
            return "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'a')
            {
                s[i] = 'a';
                break;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == 'a')
                cnt++;
        if (cnt == n)
            s[n - 1] = 'b';
        return s;
    }
};