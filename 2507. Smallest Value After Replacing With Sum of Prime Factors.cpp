#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<int, int> primeFactors(int n)
    {
        map<int, int> primeFactor;
        int cnt = 0;
        while (n % 2 == 0)
        {
            cnt++;
            n /= 2;
        }
        if (cnt)
            primeFactor[2] = cnt;
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            if (cnt)
                primeFactor[i] = cnt;
        }
        if (n > 2)
            primeFactor[n] = 1;
        return primeFactor;
    }
    int reduceN(int n)
    {
        map<int, int> mp = primeFactors(n);
        int m = 0;
        for (auto p : mp)
            m += p.first * p.second;
        return m;
    }
    int smallestValue(int n)
    {
        while (n != 0)
        {
            int m = reduceN(n);
            if (n - m == 0)
                return n;
            n -= m;
        }
        return 0;
    }
};