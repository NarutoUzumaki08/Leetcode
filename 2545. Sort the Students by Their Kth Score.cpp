#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        vector<pair<int, vector<int>>> grid;
        for (int i = 0; i < score.size(); i++)
            grid.push_back({score[i][k], score[i]});
        sort(grid.begin(), grid.end());
        vector<vector<int>> ans;
        for (int i = 0; i < grid.size(); i++)
            ans.push_back(grid[i].second);
        return ans;
    }
};