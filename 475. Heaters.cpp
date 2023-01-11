#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &houses, vector<int> &heaters, int k)
    {
        int i = 0, j = 0;
        while (i < houses.size() && j < heaters.size())
        {
            if (abs(houses[i] - heaters[j]) <= k)
                i++;
            else
                j++;
        }
        return i == houses.size();
    }
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = *max_element(houses.begin(), houses.end());
        int ans = INT_MAX;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(houses, heaters, mid))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};

// 100 101
// 1 2 100