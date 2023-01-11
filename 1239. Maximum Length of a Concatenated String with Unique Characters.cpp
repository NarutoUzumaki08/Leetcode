#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    bool check(string &s)
    {
        unordered_set<char> st(s.begin(), s.end());
        return st.size() == s.size();
    }
    int maxLength(vector<string> &arr, string curr = "", int i = 0)
    {
        n = arr.size();
        if (!check(curr))
            return 0;
        int ans = curr.size();
        for (int j = i; j < n; j++)
            ans = max(maxLength(arr, curr + arr[j], j + 1), ans);
        return ans;
    }
};


