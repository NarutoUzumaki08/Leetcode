#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<ll> pq;
        for (auto pile : gifts)
            pq.push(pile);
        ll ans = 0;
        while (k != 0)
        {
            ll curr = pq.top();
            pq.pop();
            curr=(ll)sqrt(curr);
            pq.push(curr);
        }
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};