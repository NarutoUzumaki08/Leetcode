#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkEqual(string &s)
    {
        int n = s.size();
        map<char, int> mp;
        for (auto c : s)
            mp[c]++;
        map<int, int> count;
        for (auto x : mp)
            count[x.second]++;
        return ((int)count.size() == 1);
    }
    bool equalFrequency(string word)
    {
        int n = word.size();
        string curr = "";
        for (int i = 0; i < n; i++)
        {
            string curr = word.substr(0, i) + word.substr(i + 1);
            if (checkEqual(curr))
                return true;
        }
        return false;
    }
};