#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<long long> s;
    void primeFactors(long long n)
    {
        while (n % 2 == 0)
        {
            s.insert(2);
            n = n / 2;
        }
        for (long long i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                s.insert(i);
                n = n / i;
            }
        }
        if (n > 2)
            s.insert(n);
    }
    int distinctPrimeFactors(vector<int> &nums)
    {
        int n = nums.size();
        for (auto num : nums)
            primeFactors(num);
        return s.size();
    }
};