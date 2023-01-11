#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int cnt = 0, sum = 0;
        for (auto x : nums)
        {
            if (x % 2)
                continue;
            cnt += x % 3 == 0 ? 1 : 0;
            sum += x % 3 == 0 ? x : 0;
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};