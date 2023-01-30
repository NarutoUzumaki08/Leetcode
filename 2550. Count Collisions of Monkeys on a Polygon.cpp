#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    ll mod = 1e9 + 7;
    ll pow_mod(ll n, ll p, ll mod)
    {
        ll ans = 1;
        while (p)
        {
            if (p & 1)
                ans = ans * n % mod;
            n = n * n % mod;
            p >>= 1;
        }
        return ans;
    }
    int monkeyMove(int n)
    {
        ll total = pow_mod(2, n, mod);
        ll ans = (total - 2) % mod;
        return ans < 0 ? ans + mod : ans;
    }
};