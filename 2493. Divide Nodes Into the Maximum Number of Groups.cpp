#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
class Solution
{
public:
    vector<vector<int>> connected_components;
    vector<int> adj[501];
    int n;
    int bfs(int root)
    {
        // debug(n)
        vector<int> level(n + 1, -1);
        queue<int> q;
        q.push(root);
        level[root] = 1;
        int curr_level = 1;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (level[v] == -1)
                {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
                else
                {
                    if (level[v] == level[u] || abs(level[v] - level[u]) != 1)
                        return -1;
                }
            }
            // curr_level++;
        }
        // debug(root, level);
        int mx = *max_element(level.begin(), level.end());
        return mx;
    }
    int bfs_for_every_component()
    {
        int ans = 0;
        for (auto v : connected_components)
        {
            int mx = 0;
            for (auto u : v)
            {
                if (u == -1)
                    continue;
                int temp = bfs(u);
                if (temp == -1)
                    return -1;
                mx = max(mx, temp);
            }
            ans += mx;
        }
        return ans;
    }
    void dfs(int node, vector<int> &vis, vector<int> &curr_component)
    {
        vis[node] = 1;
        curr_component.push_back(node);
        for (auto child : adj[node])
        {
            if (!vis[child])
                dfs(child, vis, curr_component);
        }
    }
    void connected_components_dfs()
    {
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vector<int> curr_component;
                dfs(i, vis, curr_component);
                connected_components.push_back(curr_component);
            }
        }
    }
    int magnificentSets(int N, vector<vector<int>> &edges)
    {
        n = N;
        // adj->resize(n + 1)
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return bfs(5);
        connected_components_dfs();
        return bfs_for_every_component();
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution obj;
    cout << obj.magnificentSets(n, edges) << endl;
    return 0;
}