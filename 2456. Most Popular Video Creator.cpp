#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        map<string, vector<pair<string, int>>> mp;
        int n = creators.size();
        for (int i = 0; i < n; i++)
        {
            pair<string, int> p = {ids[i], views[i]};
            mp[creators[i]].push_back(p);
        }
        for (auto &v : mp)
        {
            sort(v.second.begin(), v.second.end(), [](pair<string, int> &a, pair<string, int> &b)
                 {
               if(a.second==b.second)
                   return a.first<b.first;
                return a.second>b.second; });
        }
        map<string, int> big;
        vector<string> res;
        int mx = INT_MIN;
        for (auto v : mp)
        {
            int sum = 0;
            for (auto x : v.second)
                sum += x.second;
            big[v.first] = sum;
            mx = max(mx, sum);
        }
        for (auto x : big)
        {
            if (x.second == mx)
                res.push_back(x.first);
        }
        vector<vector<string>> ans;
        for (auto s : res)
            ans.push_back({s, mp[s][0].first});
        return ans;
    }
};