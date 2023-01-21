#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    vector<vector<int>> vis;
    pair<int, int> giveMeCoordinates(int num)
    {
        int row = (num - 1) / n, col = (num - 1) % n;
        if (row % 2 == 0)
            return {n - 1 - row, col};
        else
            return {n - 1 - row, n - 1 - col};
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        n = board.size();
        vector<bool> vis(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int number = curr.first, steps = curr.second;
            if (number == n * n)
                return steps;
            for (int i = 1; number + i <= n * n && i <= 6; i++)
            {
                int nextNumber = number + i;
                auto nextCoordinates = giveMeCoordinates(nextNumber);
                int nextRow = nextCoordinates.first, nextCol = nextCoordinates.second;
                if (board[nextRow][nextCol] != -1)
                    nextNumber = board[nextRow][nextCol];
                if (!vis[nextNumber])
                {
                    vis[nextNumber] = true;
                    q.push({nextNumber, steps + 1});
                }
            }
        }
        return -1;
    }
};
