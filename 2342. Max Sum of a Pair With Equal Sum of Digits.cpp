#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumOfDigits(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int> &nums)
    {
        map<int, priority_queue<int>> mp;
        for (auto num : nums)
        {
            int sum = sumOfDigits(num);
            mp[sum].push(num);
        }
        int ans = -1;
        for (auto [sum, pq] : mp)
        {
            if (pq.size() < 2)
                continue;
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            ans = max(ans, a + b);
        }
        return ans;
    }
};