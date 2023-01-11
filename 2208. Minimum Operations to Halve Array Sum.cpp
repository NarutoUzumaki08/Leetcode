#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<int> pq;
        double sum = 0.0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        int ans = 0;
        while (sum >= sum / 2)
        {
            int x = pq.top();
            sum -= x;
            sum += x / 2;
            ans++;
            if (sum = sum / 2)
                break;
            else if (x != 0)
                pq.push(x / 2);
        }
        return ans;
    }
};