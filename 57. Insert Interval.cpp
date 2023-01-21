#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool areOverlapping(vector<int> &a, vector<int> &b)
    {
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }
    vector<int> mergeIntervals(vector<int> &a, vector<int> &b)
    {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size() + 1;
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++)
        {
            vector<int> currInterval = {intervals[i][0], intervals[i][1]};
            while (i < n && areOverlapping(currInterval, intervals[i]))
            {
                currInterval = mergeIntervals(currInterval, intervals[i]);
                i++;
            }
            i--;
            ans.push_back(currInterval);
        }
        return ans;
    }
};