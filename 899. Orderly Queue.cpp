#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        int n = s.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({s[i], i});
        sort(v.begin(), v.end());
        string ans = "";
        ans += s.substr(v[0].second) + s.substr(0, v[0].second);
        if (k == 1)
            return ans;
        sort(s.begin(), s.end());
        return s;
    }
};