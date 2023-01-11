#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int cnt = 0;
        map<string, int> similar, different;
        for (auto word : words)
        {
            if (word[0] == word[1])
                similar[word]++;
            else
                different[word]++;
        }
        for (auto [word, freq] : similar)
        {
            if (freq > 1)
            {
                if (freq % 2 == 1)
                    freq--;
                cnt += 2 * freq;
                similar[word] -= freq;
            }
        }
        for (auto [word, val] : different)
        {
            string rev = word;
            reverse(rev.begin(), rev.end());
            cnt += 4 * min(val, different[rev]);
            different[word] = 0, different[rev] = 0;
        }
        for (auto [word, freq] : similar)
        {
            if (freq)
            {
                cnt += 2;
                break;
            }
        }
        return cnt;
    }
};