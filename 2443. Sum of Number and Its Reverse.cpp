#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
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
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = 1; i <= num; i++)
        {
            int rev = reverseDigitsofNumber(i);
            if (rev + i == num)
                return true;
        }
        return false;
    }
};