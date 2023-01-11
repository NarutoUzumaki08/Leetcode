#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> SieveOfEratosthenes(int range, int left)
    {
        vector<int> isPrime(range + 1, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 4; i < isPrime.size(); i += 2)
            isPrime[i] = 0;
        for (int i = 3; i * i < isPrime.size(); i += 2)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }
        vector<int> primes;
        for (int i = 0; i < isPrime.size(); i++)
        {
            if (isPrime[i] && i >= left)
                primes.push_back(i);
        }
        return primes;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes = SieveOfEratosthenes(right, left);
        int mn = INT_MAX, l = -1, r = 1;
        for (int i = 0; i < primes.size() - 1 && primes.size() != 0; i++)
        {
            int diff = primes[i + 1] - primes[i];
            if (diff < mn)
            {
                mn = diff;
                l = primes[i], r = primes[i + 1];
            }
        }
        return {l, r};
    }
};