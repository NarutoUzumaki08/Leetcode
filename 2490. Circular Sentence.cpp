#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        stringstream ss(sentence);
        vector<string> words;
        string word;
        while (ss >> word)
            words.push_back(word);
        words.push_back(words[0]);
        int n = words.size();
        for (int i = 0; i < n - 1; i++)
        {
            int N = words[i].size(), M = words[i + 1].size();
            if (words[i][N - 1] != words[i + 1][0])
                return false;
        }
        return true;
    }
};