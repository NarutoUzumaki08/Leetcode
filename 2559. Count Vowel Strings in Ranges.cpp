#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> prefix(n);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            int m = words[i].size();
            if (isVowel(words[i][0]) && isVowel(words[i][m - 1]))
                curr++;
            prefix[i] = curr;
        }
        vector<int> ans;
        for (auto q : queries)
        {
            int l = q[0], r = q[1];
            if (l == 0)
            {
                ans.push_back(prefix[r]);
                continue;
            }
            int currAns = prefix[r] - prefix[l - 1];
            ans.push_back(currAns);
        }
        return ans;
    }
};