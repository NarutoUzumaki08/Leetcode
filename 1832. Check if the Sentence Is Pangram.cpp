#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkIfPangram(string s)
    {
        set<char> st(s.begin(), s.end());
        return st.size() == 26;
    }
};