#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(string s1, string s2)
    {
        map<int, int> mp;
        for (auto c : s1)
            mp[c]++;
        for (auto c : s2)
        {
            bool check = false;
            for (int j = c - 'a'; j < 26; j++)
            {
                if (mp.find(j) != mp.end())
                {
                    mp[j]--;
                    if (mp[j] == 0)
                        mp.erase(j);
                    check = true;
                    break;
                }
            }
            if (!check)
                return false;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2)
    {
        return check(s1, s2) || check(s2, s1);
    }
};
