#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        map<int, int> mp;
        for (auto person : trust)
        {
            mp[person[1]]++;
            mp[person[0]]--;
        }
        for (auto person : mp)
            if (person.second == n - 1)
                return person.first;
        return -1;
    }
};