#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;
        for (auto c : t)
            mp[c]++;
        int n = s.size(), i = 0, j = 0, len = INT_MAX, counter = t.size(), start;
        for (; j < n;)
        {
            if (mp[s[j]] > 0)
                counter--;
            mp[s[j]]--, j++;
            while (counter == 0)
            {
                if ((j - i) < len)
                {
                    len = j - i;
                    start = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    counter++;
                i++;
            }   
        }
        if (len == INT_MAX)
            return "";
        return s.substr(start, len);
    }
};