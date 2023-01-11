#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    bool check(map<char, int> &curr, int k)
    {
        for (char ch = 'a'; ch <= 'c'; ch++)
            if (curr[ch] < k)
                return false;
        return true;
    }
    int takeCharacters(string s, int k)
    {
        n = s.size();
        map<char, int> mp;
        for (auto ch : s)
            mp[ch]++;
        int ans = INT_MIN;
        if (check(mp, k))
            ans = 0;
        for (int i = 0, j = 0; i < n && j < n; j++)
        {
            mp[s[j]]--;
            while (!check(mp, k) && i <= j)
                mp[s[i++]]++;
            if (check(mp, k))
                ans = max(ans, j - i + 1);
        }
        return ans == INT_MIN ? -1 : n - ans;
    }
};