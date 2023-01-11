#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> dp[101][101];
    int n;
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {-1, -1}};
    pair<int, int> solve(int i, int j, vector<string> &board)
    {
        if (i < 0 || j < 0 || board[i][j] == 'X')
            return {INT_MIN, 0};
        if (i == 0 && j == 0)
            return {0, 1};
        if (dp[i][j].first != -1)
            return dp[i][j];
        int val = board[i][j] == 'S' ? 0 : board[i][j] - '0';
        int sum = INT_MIN, cnt = 0;
        for (auto d : dir)
        {
            int x = i + d.first, y = j + d.second;
            auto p = solve(x, y, board);
            if (p.first + val > sum)
            {
                sum = p.first + val;
                cnt = p.second;
            }
            else if (p.first + val == sum)
                cnt = (cnt + p.second) % 1000000007;
        }
        return dp[i][j] = {sum, cnt};
    }
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        n = board.size();
        memset(dp, -1, sizeof(dp));
        auto p = solve(n - 1, n - 1, board);
        if (p.first < 0)
            return {0, 0};
        return {p.first, p.second};
    }
};