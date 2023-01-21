#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long sum(long long total, long long val)
    {
        return total * val - (total * (total + 1)) / 2;
    }
    int maxValue(int n, int index, int maxSum)
    {
        long long l = 1, r = 1e9;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long leftSum = sum(mid, index + 1);
            long long rightSum = sum(mid, n - index);
        }
    }
};