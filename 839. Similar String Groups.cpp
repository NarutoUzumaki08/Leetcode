#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef int ll;
using namespace std;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vp;
#define f(i, n) for (ll i = 0; i < n; i++)
#define rf(i, n) for (ll i = n - 1; i >= 0; i--)
#define F first
#define S second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define Map map<ll, ll>
#define Set set<ll>
#define rep(i, j, k) for (int i = j; i < k; i++)
#define inf 1000000000000000005
ll MOD = 1000000000 + 7;
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
class UnionFind
{
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int Find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = Find(parent[u]); // Path compression -> logN
    }
    bool Union(int u, int v)
    {
        int pu = Find(u), pv = Find(v);
        if (pu == pv)
            return false;
        if (size[pu] < size[pv])
        { // merge u into v
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        return true;
    }
};

class Solution
{
public:
    bool isSimilar(string &a, string &b)
    {
        int n = a.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                cnt++;
                if (cnt > 2)
                    return false;
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size(), groups = n;
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
                if (isSimilar(strs[i], strs[j]))
                {
                    if (uf.Union(i, j))
                        groups--;
                }
        }
        return groups;
    }
};