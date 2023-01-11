#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<char> vowels;
        for (auto c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                vowels.push_back(c);
        }
        reverse(vowels.begin(), vowels.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = vowels[j];
                j++;
            }
        }
        return s;
    }
};