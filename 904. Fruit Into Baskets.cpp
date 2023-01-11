#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        map<int, int> mp;
        int ans = 0;
        for (int i = 0, j = 0; j < n; j++)
        {
            while (mp.size() > 2)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                i++;
            }
            int curr = 0;
            for (auto [type, count] : mp)
                curr += count;
            ans = max(ans, curr);
            mp[fruits[j]]++;
        }
        return ans;
    }
};