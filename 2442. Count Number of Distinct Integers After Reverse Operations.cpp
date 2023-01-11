#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<int> s;
    int reverseDigitsofNumber(int n)
    {
        int rev = 0;
        while (n)
        {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int> &nums)
    {
        for (auto x : nums)
        {
            s.insert(x);
            s.insert(reverseDigitsofNumber(x));
        }
        return (int)s.size();
    }
};