#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    long long dividePlayers(vector<int> &skill)
    {
        ll n = skill.size();
        if (n == 2)
            return skill[0] * skill[1];
        vector<pair<ll, ll>> teams;
        map<ll, ll> mp;
        for (auto val : skill)
            mp[val]++;
        ll total_sum = accumulate(skill.begin(), skill.end(), 0LL);
        if (total_sum % (n / 2) != 0)
            return -1;
        ll team_sum = (total_sum / (n / 2));
        for (auto &x : mp)
        {
            ll player1 = x.first, player2 = team_sum - player1;
            if(mp[player1]==0)
                continue;
            if (player1 != player2)
            {
                if (mp[player1] != mp[player2])
                    return -1;
                for (ll i = 0; i < mp[player1]; i++)
                    teams.push_back({player1, player2});
                mp[player1] = mp[player2] = 0;
            }
            else
            {
                if (mp[player1] % 2 != 0)
                    return -1;
                for (ll i = 0; i < mp[player1]; i += 2)
                    teams.push_back({player1, player2});
                mp[player1] = 0;
            }
        }
        ll res = 0;
        for (auto &x : teams)
            res += x.first * x.second;
        return res;
    }
};
// int main()
// {
//     Solution *sol = new Solution();
//     vector<int> skill = {3, 2, 5, 1, 3, 4};
//     cout << sol->dividePlayers(skill) << endl;
//     return 0;
// }