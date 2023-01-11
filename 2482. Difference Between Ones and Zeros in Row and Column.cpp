#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> row(n), col(m);
        vector<vector<int>> diff(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            int ones = 0, zero = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    ones++;
                else
                    zero++;
            }
            row[i] = {ones, zero};
        }
        for (int j = 0; j < m; j++)
        {
            int ones = 0, zero = 0;
            for (int i = 0; i < n; i++)
            {
                if (grid[i][j] == 1)
                    ones++;
                else
                    zero++;
            }
            col[j] = {ones, zero};
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int curr = row[i].first - row[i].second + col[j].first - col[j].second;
                diff[i][j] = curr;
            }
        }
        return diff;
    }
};