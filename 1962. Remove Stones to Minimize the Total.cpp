#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int n = piles.size();
        priority_queue<int> pq;
        for (auto pile : piles)
            pq.push(pile);
        while (k--)
        {
            int curr = pq.top();
            pq.pop();
            pq.push(curr - curr / 2);
        }
        int ans = 0;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};