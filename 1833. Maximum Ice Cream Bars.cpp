#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (auto cost : costs)
        {
            if (coins >= cost)
                ans++, coins -= cost;
            else
                break;
        }
        return ans;
    }
};