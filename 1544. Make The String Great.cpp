#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            bool check = false;
            if (!st.empty() && (abs(st.top() - s[i]) == 32))
            {
                st.pop();
                check = true;
            }
            if (check == false)
                st.push(s[i]);
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};