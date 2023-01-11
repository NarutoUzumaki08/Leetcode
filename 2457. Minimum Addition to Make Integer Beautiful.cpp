#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
   long long sumOfDigits(long long n)
    {
       long long sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target)
    {
        long long base = 1, m = n;
        while (sumOfDigits(n) > target)
        {
            n = n / 10 + 1;
            base *= 10;
        }
        return abs(n * base - m);
    }
};