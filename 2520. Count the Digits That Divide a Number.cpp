#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countDigits(int num)
    {
        int n = num, ans = 0;
        while (num)
        {
            int d = num % 10;
            if (n % d == 0)
                ans++;
            num /= 10;
        }
        return ans;
    }
};