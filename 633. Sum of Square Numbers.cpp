#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long a = 0, b = sqrt(c);
        while (a <= b)
        {
            long long c1 = a * a + b * b;
            if (c1 == c)
                return true;
            if (c1 > c)
                b--;
            else
                a++;
        }
        return false;
    }
};