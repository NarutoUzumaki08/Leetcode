#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[100005];
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                adj[i].push_back(leftChild[i]);
            if (rightChild[i] != -1)
                adj[i].push_back(rightChild[i]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
    }
};


