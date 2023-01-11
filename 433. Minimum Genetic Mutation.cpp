#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        map<string, int> present;
        for (auto str : bank)
            present[str] = 1;
        if (!present[end])
            return -1;
        map<string, int> vis;
        int steps = 0;
        queue<string> q;
        q.push(start);
        vis[start] = 1;
        vector<char> gene = {'A', 'G', 'C', 'T'};
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string curr = q.front();
                q.pop();
                if (curr == end)
                    return steps;
                for (int i = 0; i < 8; i++)
                {
                    char before = curr[i];
                    for (auto g : gene)
                    {
                        curr[i] = g;
                        if (present[curr])
                        {
                            if (!vis[curr])
                            {
                                q.push(curr);
                                vis[curr] = 1;
                            }
                        }
                    }
                    curr[i] = before;
                }
            }
            steps++;
        }
        return -1;
    }
};