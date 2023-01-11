#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MODADD(a, b, m) ((((a) % m) + ((b) % m)) % m)
const ll M = 1e9 + 7;
class Solution
{
public:
    ll sum(ll n)
    {
        return (n * (n + 1)) / 2;
    }

    bool isPossible(vector<int> &a, int k, ll orders)
    {
        ll cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] <= k)
                continue;
            cnt += (a[i] - k); // a[i] - (k + 1) + 1
        }

        return cnt >= orders;
    }

    int maxProfit(vector<int> &a, int orders)
    {
        int n = a.size();

        sort(a.begin(), a.end());

        ll k = 1e9;

        ll beg = 0, end = 1e9;

        while (beg <= end)
        {
            ll mid = (beg + end) / 2;

            if (isPossible(a, mid, orders))
            {
                k = mid;
                beg = mid + 1;
            }
            else
                end = mid - 1;
        }

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] <= k)
                continue;
            ans = MODADD(ans, sum(a[i]) - sum(k), M);
            orders -= (a[i] - k);
        }

        ll freq_of_k = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < k)
                continue;
            freq_of_k++;
        }

        ans = MODADD(ans, orders * k, M);

        return ans;
    }
};
