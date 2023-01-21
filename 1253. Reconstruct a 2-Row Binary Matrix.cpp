#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<vector<int>> grid;
    bool check(int upper, int lower, vector<int> &colsum)
    {
        int upperSum = 0, lowerSum = 0;
        for (int i = 0; i < n; i++)
        {
            upperSum += grid[0][i];
            lowerSum += grid[1][i];
            int currCol = grid[0][i] + grid[1][i];
            if (currCol != colsum[i])
                return false;
        }
        return upperSum == upper && lowerSum == lower;
    }
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        n = colsum.size();
        grid = vector<vector<int>>(2, vector<int>(n, 0));
        int Upper = upper, Lower = lower;
        for (int i = 0; i < n; i++)
        {
            if (colsum[i] == 2)
            {
                grid[0][i] = 1, grid[1][i] = 1;
                upper--, lower--;
            }
            else if (colsum[i] == 1)
            {
                if (upper > lower)
                    grid[0][i] = 1, upper--;
                else
                    grid[1][i] = 1, lower--;
            }
        }
        return check(Upper, Lower, colsum) ? grid : vector<vector<int>>();
    }
};