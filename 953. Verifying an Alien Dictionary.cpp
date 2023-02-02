#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++)
            mp[order[i]] = i;
        for (int i = 0; i < words.size() - 1; i++)
        {
            string currWord = words[i], nextWord = words[i + 1];
            int m = currWord.size(), n = nextWord.size();
            bool check = false;
            for (int j = 0; j < min(m, n); j++)
            {
                if (mp[currWord[j]] < mp[nextWord[j]])
                {
                    check = true;
                    break;
                }
                else if (mp[currWord[j]] > mp[nextWord[j]])
                    return false;
            }
            if (!check && m > n)
                return false;
        }
        return true;
    }
};