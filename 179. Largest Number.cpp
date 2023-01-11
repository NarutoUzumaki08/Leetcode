#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(const string &a, const string &b)
    {
        return a + b > b + a;
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> numbers;
        int cnt = 0, n = nums.size();
        for (auto num : nums)
        {
            if (num == 0)
                cnt++;
            numbers.push_back(to_string(num));
        }
        sort(numbers.begin(), numbers.end(), comp);
        string ans = "";
        for (auto str : numbers)
            ans += str;
        if (cnt == n)
            return "0";
        return ans;
    }
};