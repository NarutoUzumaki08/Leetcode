#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool sortBysec(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.second < b.second);
    }
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int n = plantTime.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {plantTime[i], growTime[i]};
        sort(v.begin(), v.end(), sortBysec);
        int day = v[0].first + v[0].second, prevBloomTime = v[0].first;
        for (int i = 1; i < n; i++)
        {
            int currDay = prevBloomTime + v[i].first + v[i].second;
            day = max(day, currDay);
            prevBloomTime += v[i].first;
        }
        return day;
    }
};