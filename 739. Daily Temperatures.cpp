#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr_temp = temperatures[i];
            while (!st.empty() && st.top().first <= curr_temp)
                st.pop();
            if (!st.empty())
                ans[i] = st.top().second - i;
            st.push({curr_temp, i});
        }
        return ans;
    }
};