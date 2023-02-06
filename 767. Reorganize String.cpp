#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {
        map<char, int> mp;
        for (auto c : s)
            mp[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto p : mp)
            pq.push({p.second, p.first});
        string ans = "";
        while (pq.size() >= 2)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            if (--p1.first)
                pq.push(p1);
            if (--p2.first)
                pq.push(p2);
        }
        if (pq.size())
        {
            auto p = pq.top();
            if (p.first > 1)
                return "";
            ans += p.second;
        }
        return ans;
    }
};