#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string pushDominoes(string domino)
    {
        int n = domino.size();
        vector<int> leftForce(n, -1), rightForce(n, -1);
        int currIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (domino[i] == 'R')
            {
                currIdx = i;
                rightForce[i] = i;
                continue;
            }
            if (currIdx != -1 && domino[i] == 'L')
                currIdx = -1;
            else
                rightForce[i] = currIdx;
        }
        currIdx = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (domino[i] == 'L')
            {
                currIdx = i;
                leftForce[i] = i;
                continue;
            }
            if (currIdx != -1 && domino[i] == 'R')
                currIdx = -1;
            else
                leftForce[i] = currIdx;
        }
        string finalState = "";
        for (int i = 0; i < n; i++)
        {
            if (leftForce[i] == -1 && rightForce[i] == -1)
                finalState += '.';
            else if (leftForce[i] == -1)
                finalState += 'R';
            else if (rightForce[i] == -1)
                finalState += 'L';
            else
            {
                int leftDist = abs(i - leftForce[i]);
                int rightDist = abs(rightForce[i] - i);
                if (leftDist == rightDist)
                    finalState += '.';
                else if (leftDist < rightDist)
                    finalState += 'L';
                else
                    finalState += 'R';
            }
        }
        return finalState;
    }
};