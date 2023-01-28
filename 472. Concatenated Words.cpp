#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<string, int> mp;
    vector<string> ans;
    // map<string, int> dp;
    bool dfs(string s)
    {
        if (mp[s] > 0)
            return true;
        for (int i = 1; i < s.size(); i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (mp[left] > 0 && dfs(right))
                return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        for (auto word : words)
            mp[word]++;
        for (auto word : words)
        {
            mp[word]--;
            if (dfs(word))
                ans.push_back(word);
            mp[word]++;
        }
        return ans;
    }
};