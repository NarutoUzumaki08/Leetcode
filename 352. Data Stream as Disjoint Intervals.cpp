#include <bits/stdc++.h>
using namespace std;
class SummaryRanges
{
public:
    set<int> nums;
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        nums.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        if (nums.size() == 0)
            return {};
        vector<vector<int>> ans;
        int left = -1, right = -1;
        for (auto num : nums)
        {
            if (left < 0)
                left = num, right = num;
            else if (num == right + 1)
                right = num;
            else
            {
                ans.push_back({left, right});
                left = num, right = num;
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};