#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long ceil(long long a, long long b)
    {
        return (a % b == 0 ? a / b : a / b + 1);
    }
    long long maxKelements(vector<int> &nums, int k)
    {
        long long ans = 0;
        priority_queue<long long> pq;
        for (auto num : nums)
            pq.push(num);
        while (k != 0)
        {
            long long top = pq.top();
            pq.pop();
            ans += top;
            pq.push(ceil(top, 3));
            k--;
        }
        return ans;
    }
};