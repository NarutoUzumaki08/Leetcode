#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int similarPairs(vector<string> &words)
    {
        int n = words.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            set<char> word1;
            for (auto c : words[i])
                word1.insert(c);
            for (int j = i + 1; j < n; j++)
            {
                set<char> word2;
                for (auto c : words[j])
                    word2.insert(c);
                if (word1 == word2)
                    ans++;
            }
        }
        return ans;
    }
};