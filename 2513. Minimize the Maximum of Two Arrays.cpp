#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        long long l = 1, r = 1e9, ans = LONG_LONG_MAX;
        while (l <= r)
        {
            long long x = (l + r) / 2;
            long long only1 = x - (x / divisor1), only2 = x - (x / divisor2);
            long long LCM = (1ll * divisor1 * divisor2) / __gcd(divisor1, divisor2);
            long long both = x - (x / LCM);
            if (only1 >= uniqueCnt1 && only2 >= uniqueCnt2 && both >= uniqueCnt1 + uniqueCnt2)
            {
                ans = min(ans, x);
                r = x - 1;
            }
            else
                l = x + 1;
        }
        return ans;
    }
};