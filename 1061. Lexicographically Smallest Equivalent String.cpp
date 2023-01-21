#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> rank, parent;
    int n = 27;
    void make_set()
    {
        rank = vector<int>(n, 0);
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find_parent(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_parent(parent[v]);
    }
    void union_set(int a, int b)
    {
        a = find_parent(a), b = find_parent(b);
        if (a != b)
        {
            if (a > b)
                swap(a, b);
            parent[b] = a;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.size();
        make_set();
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                union_set(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for (auto &ch : baseStr)
            ans += char(find_parent(ch - 'a') + 'a');
        return ans;
    }
};