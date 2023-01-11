#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkBox(vector<vector<char>> &board, int i, int j)
    {
        map<char, int> mp;
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 3; l++)
            {
                if (board[i + k][j + l] == '.')
                    continue;
                mp[board[i + k][j + l]]++;
                if (mp[board[i + k][j + l]] > 1)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            map<char, int> row;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                row[board[i][j]]++;
                if (row[board[i][j]] > 1)
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            map<char, int> col;
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                col[board[j][i]]++;
                if (col[board[j][i]] > 1)
                    return false;
            }
        }
        int i = 0, j = 0;
        for (int k = 0; k < 9; k++)
        {
            if (!checkBox(board, i, j))
                return false;
            j += 3;
            if (j == 9)
                j = 0, i += 3;
        }
        return true;
    }
};