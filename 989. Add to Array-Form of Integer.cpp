#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int n = num.size(), carry = 0, i;
        vector<int> ans;
        for (i = n - 1; i >= 0 && k != 0; i--)
        {
            int d = k % 10;
            k /= 10;
            int curr = num[i] + d + carry;
            carry = curr / 10;
            curr %= 10;
            ans.push_back(curr);
        }
        while (i >= 0)
        {
            int curr = num[i] + carry;
            carry = curr / 10;
            curr %= 10;
            ans.push_back(curr);
            i--;
        }
        while (k != 0)
        {
            int d = k % 10;
            k /= 10;
            int curr = d + carry;
            carry = curr / 10;
            curr %= 10;
            ans.push_back(curr);
        }
        if (carry != 0)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};