#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});
        string ans = "";
        while (pq.size() >= 2)
        {
            pair<int, char> p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();
            for (int i = 0; i < min(2, p1.first); i++)
                ans += p1.second;
            p1.first -= min(2, p1.first);
            if (p2.first >= 2 && p2.first > p1.first)
            {
                ans += p2.second, ans += p2.second;
                p2.first -= 2;
            }
            else
            {
                ans += p2.second;
                p2.first--;
            }
            if (p1.first)
                pq.push(p1);
            if (p2.first)
                pq.push(p2);
        }
        if (!pq.empty())
        {
            for (int i = 0; i < min(2, pq.top().first); i++)
                ans += pq.top().second;
        }
        return ans;
    }
};