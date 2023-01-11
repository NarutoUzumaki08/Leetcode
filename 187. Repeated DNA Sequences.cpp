#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        vector<string> ans;
        map<string, int> mp;
        for (int i = 0; i < n - 9; i++)
        {
            string curr = s.substr(i, 10);
            mp[curr]++;
        }
        for (auto x : mp)
        {
            if (x.second > 1)
                ans.push_back(x.first);
        }
        return ans;
    }
};