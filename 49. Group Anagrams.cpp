#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, set<string>> mp;
        for (auto s : strs)
        {
            sort(s.begin(), s.end());
            mp[s].insert(s);
        }
        vector<vector<string>> ans;
        for (auto v : mp)
        {
            vector<string> temp;
            for (auto s : v.second)
                temp.push_back(s);
            ans.push_back(temp);
        }
        return ans;
    }
};