#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkDistances(string s, vector<int> &distance)
    {
        int n = s.size();
        for (int i = 0; i < 26; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == 'a' + i)
                    v.push_back(j);
            }
            if(v.size() == 0)
                continue;
            if (abs(v[0] - v[1] - 1) != distance[i])
                return false;
        }
        return true;
    }
};