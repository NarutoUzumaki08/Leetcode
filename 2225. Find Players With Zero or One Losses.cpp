#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int n = matches.size();
        vector<int> wins, loss;
        set<int> st;
        for (auto &x : matches)
            st.insert(x[0]);
        for (auto &x : matches)
            st.erase(x[1]);
        map<int, int> mp;
        for (auto &x : matches)
            mp[x[1]]++;
        for (auto &x : st)
            wins.push_back(x);
        for (auto &x : mp)
            if (x.second == 1)
                loss.push_back(x.first);
        return {wins, loss};
    }
};