#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto q : queries)
        {
            int u = q[0], v = q[1], cnt = 1;
            while (u != v)
            {
                if (u > v)
                    swap(u, v);
                v /= 2;
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};