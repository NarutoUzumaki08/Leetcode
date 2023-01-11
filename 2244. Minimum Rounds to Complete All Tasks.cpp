#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int n = tasks.size();
        map<int, int> mp;
        for (auto task : tasks)
            mp[task]++;
        int ans = 0;
        for (auto [task, cnt] : mp)
        {
            if ((cnt % 3) == 0)
            {
                ans = cnt / 3;
                continue;
            }
            else if (cnt % 3 == 1)
            {
                int x = cnt / 3;
                x--;
                ans += x;
                cnt -= 3 * x;
                ans += cnt / 2;
            }
            else
                ans = cnt / 3 + 1;
        }
        cout << ans << endl;
    }
};

// 1 1 1 1 1 1 1