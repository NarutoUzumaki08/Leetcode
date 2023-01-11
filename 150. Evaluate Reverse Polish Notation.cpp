#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    long long stringToInt(string s)
    {
        long long n = s.size(), num = 0;
        bool sign = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-')
                sign = true;
            else
                num = num * 10 + (s[i] - '0');
        }
        if (sign)
            num = -num;
        return num;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        for (auto t : tokens)
        {
            string curr = t;
            long long n = curr.size();
            if (n == 1 && isOperator(curr[0]))
            {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                if (curr[0] == '+')
                    st.push(b + a);
                else if (curr[0] == '-')
                    st.push(b - a);
                else if (curr[0] == '*')
                    st.push(b * a);
                else if (curr[0] == '/')
                    st.push(b / a);
            }
            else
            {
                long long num = stringToInt(curr);
                st.push(num);
            }
        }
        return st.top();
    }
};