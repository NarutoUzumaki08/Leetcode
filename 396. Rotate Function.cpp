#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxRotateFunction(vector<int> &a)
    {
        int sum = 0, ans = 0, curr = 0;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            curr += (i * a[i]);
        }
        ans = curr;
        for (int i = 1, j; i < n; i++)
        {
            j = i + n - 1;
            int removed = (i - 1) * a[i - 1], added = j * a[j % n];
            curr = curr - removed + added - sum;
            ans = max(ans, curr);
        }

        return ans;
    }
};