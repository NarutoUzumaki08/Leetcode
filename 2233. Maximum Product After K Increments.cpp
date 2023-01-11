#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
            pq.push(nums[i]);
        while (k--)
        {
            int x = pq.top();
            pq.pop();
            pq.push(x + 1);
        }
        long long product = 1, mod = 1e9 + 7;
        while (!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            product = (product * x) % mod;
        }
        return product;
    }
};