#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &exp)
    {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        for (int currDay = 1; currDay <= 1e5; currDay++)
        {
            if (currDay <= n)
            {
                if (exp[currDay - 1] && apples[currDay - 1])
                    pq.push({exp[currDay - 1] + currDay - 1, apples[currDay - 1]});
            }
            if (pq.empty())
                break;
            ans++;
            auto p = pq.top();
            pq.pop();
            p.second--;
            if (p.second)
                pq.push(p);
            while (!pq.empty() && pq.top().first <= currDay)
                pq.pop();
        }
        return ans;
    }
};