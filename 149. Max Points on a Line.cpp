#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkPointOnLine(vector<double> &Line, double x1, double y1)
    {
        double a = Line[0], b = Line[1], c = Line[2];
        return (a * x1 + b * y1 == c);
    }
    vector<double> getTheLine(pair<double, double> P, pair<double, double> Q)
    {
        // ax+by=c
        double a = Q.second - P.second, b = P.first - Q.first;
        double c = a * (P.first) + b * (P.second);
        return {a, b, c};
    }
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                vector<double> Line = getTheLine({points[i][0], points[i][1]}, {points[j][0], points[j][1]});
                int count = 0;
                for (int k = 0; k < n; k++)
                {
                    if (checkPointOnLine(Line, points[k][0], points[k][1]))
                        count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};