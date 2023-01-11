    #include <bits/stdc++.h>
    #include "ext/pb_ds/assoc_container.hpp"
    #include "ext/pb_ds/tree_policy.hpp"
    using namespace std;
    using namespace __gnu_pbds;
    template <class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    template <class key, class value, class cmp = std::less<key>>
    using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
    typedef long long ll;
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
    class Solution
    {
    public:
        ll MOD = 1e9 + 7;
        int countPaths(int n, vector<vector<int>> &roads)
        {
            vp adj[n];
            for (auto &road : roads)
            {
                adj[road[0]].push_back({road[1], road[2]});
                adj[road[1]].push_back({road[0], road[2]});
            }
            vi dist(n, INT_MAX), ways(n, 0);
            priority_queue<pi, vp, greater<>> pq;
            dist[0] = 0;
            ways[0] = 1;
            pq.push({0, 0});
            while (!pq.empty())
            {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u])
                    continue;
                for (auto [v, w] : adj[u])
                {
                    if (dist[v] > d + w)
                    {
                        dist[v] = d + w;
                        ways[v] = ways[u];
                        pq.push({dist[v], v});
                    }
                    else if (dist[v] == d + w)
                        ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
            return ways[n - 1];
        }
    };