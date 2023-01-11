#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        map<char, int> mp1, mp2;
        set<char> s1, s2;
        for (auto c : word1)
            mp1[c]++, s1.insert(c);
        for (auto c : word2)
            mp2[c]++, s2.insert(c);
        vector<int> v1, v2;
        for (auto &e : mp1)
            v1.push_back(e.second);
        for (auto &e : mp2)
            v2.push_back(e.second);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2 && s1 == s2;
    }
};