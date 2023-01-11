#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i])
                st.pop();
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        vector<int> res;
        for (int i = 0; i < n; i++)
            res.push_back(ans[i]);
        return res;
    }
};