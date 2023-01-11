#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPresent(char ch, map<char, int> mp)
    {
        if (mp.find(ch) != mp.end())
            return true;
        return false;
    }
    bool check(map<char, int> &mp1, map<char, int> &mp2)
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (isPresent(ch, mp1))
            {
                map<char, int> curr1 = mp1, curr2 = mp2;
                curr1[ch]--;
                if (curr1[ch] == 0)
                    curr1.erase(ch);
                curr2[ch]++;
                for (auto [x, cnt] : mp2)
                {
                    curr2[x]--;
                    if (curr2[x] == 0)
                        curr2.erase(x);
                    curr1[x]++;
                    if (curr1.size() == curr2.size())
                        return true;
                    curr1[x]--;
                    if (curr1[x] == 0)
                        curr1.erase(x);
                    curr2[x]++;
                }
            }
        }
        return false;
    }
    bool isItPossible(string word1, string word2)
    {
        map<char, int> mp1, mp2;
        for (auto ch : word1)
            mp1[ch]++;
        for (auto ch : word2)
            mp2[ch]++;
        return check(mp1, mp2) || check(mp2, mp1);
    }
};