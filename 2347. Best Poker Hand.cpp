#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string bestHand(vector<int> &rank, vector<char> &suit)
    {
        map<int, int> suits, ranks;
        int n = rank.size();
        for (int i = 0; i < n; i++)
            suits[suit[i] - 'a']++, ranks[rank[i]]++;
        if (suits.size() == 1)
            return "Flush";
        for (auto [rank, count] : ranks)
        {
            if (count >= 3)
                return "Three of a Kind";
        }
        if (ranks.size() != 5)
            return "Pair";
        return "High Card";
    }
};