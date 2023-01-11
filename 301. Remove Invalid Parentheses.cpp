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

class Solution
{
public:
    int moves(string s)
    {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.size() == 0)
                    st.push(s[i]);
                else if (st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return (int)st.size();
    }
    void solve(unordered_set<string> &res, int removals, string curr, vector<string> &ans)
    {
        if (removals == 0)
        {
            if (moves(curr) == 0)
                ans.PB(curr);
            return;
        }
        int n = curr.size();
        for (int i = 0; i < n; i++)
        {
            if (curr[i] != '(' && curr[i] != ')')
                continue;
            string left = curr.substr(0, i), right(curr.substr(i + 1));

            if (res.find(left + right) == res.end())
            {
                res.insert(left + right);
                solve(res, removals - 1, left + right, ans);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int move = moves(s);
        unordered_set<string> res;
        vector<string> ans;
        string temp = "";
        solve(res, move, s, ans);
        return ans;
    }
};


//   )(((()))