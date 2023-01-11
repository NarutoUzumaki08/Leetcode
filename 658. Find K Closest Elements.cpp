#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &a, int k, int x)
    {
        int n = a.size(), idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        int i = idx - 1, j = idx;
        for (int time = 1; time <= k; time++)
        {
            int left = i >= 0 ? abs(a[i] - x) : INT_MAX;
            int right = j < n ? abs(a[j] - x) : INT_MAX;
            if (left <= right)
                i--;
            else
                j++;
        }
        return vector<int>(a.begin() + i + 1, a.begin() + j);
    }
};