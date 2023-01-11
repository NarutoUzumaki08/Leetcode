#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    bool halvesAreAlike(string s)
    {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (isVowel(s[i]))
                cnt++;
        }
        for (int i = n / 2; i < n; i++)
        {
            if (isVowel(s[i]))
                cnt--;
        }
        return cnt == 0;
    }
};