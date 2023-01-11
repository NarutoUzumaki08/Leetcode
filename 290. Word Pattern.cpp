#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string giveMeString(string s)
    {
        char j = 'a';
        string t = "";
        map<string, char> mp;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            if (mp.find(word) == mp.end())
            {
                mp[word] = j;
                j++;
            }
            t += mp[word];
        }
        return t;
    }
    bool wordPattern(string pattern, string s)
    {
        string t1 = "", t2 = giveMeString(s);
        char j = 'a';
        map<char, string> mp;
        for (auto e : pattern)
        {
            if (mp.find(e) == mp.end())
            {
                mp[e] = j;
                j++;
            }
            t1 += mp[e];
        }
        return t1 == t2;
    }
};