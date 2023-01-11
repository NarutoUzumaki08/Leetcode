#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> vis;
    int n;
    int dfs(vector<vector<int>> &pos, int i)
    {
        vis[i] = 1;
        int ans = 0;
        int cur_row = pos[i][0], cur_col = pos[i][1];
        for (int j = 0; j < n; j++)
        {
            if (vis[j])
                continue;
            int row = pos[j][0], col = pos[j][1];
            if (row == cur_row || col == cur_col)
                ans += dfs(pos, j) + 1;
        }
        return ans;
    }
    int removeStones(vector<vector<int>> &stones)
    {
        n = stones.size();
        vis = vector<int>(n, 0);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            res += dfs(stones, i);
        }
        return res;
    }
};