#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kadaneAlgo(vector<int> &nums, int type)
    {
        int ansSum = type == 1 ? INT_MIN : INT_MAX, currSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            if (type == 1)
                ansSum = max(ansSum, currSum);
            else
                ansSum = min(ansSum, currSum);
            if (currSum < 0 && type == 1)
                currSum = 0;
            else if (currSum > 0 && type == 2)
                currSum = 0;
        }
        return ansSum;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxSum = kadaneAlgo(nums, 1), minSum = kadaneAlgo(nums, 2);
        if (sum == minSum)
            return maxSum;
        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }
};

// 5 -3 5 5 -3 5