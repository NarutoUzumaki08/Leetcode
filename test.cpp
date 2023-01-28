#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
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
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type,
//              less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_multiset;
#define int long long
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vp;
#define f(i, n) for (int i = 0; i < n; i++)
#define rf(i, n) for (int i = n - 1; i >= 0; i--)
#define F first
#define S second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define Map map<int, int>
#define Set set<int>
#define rep(i, j, k) for (int i = j; i < k; i++)
#define inf 1000000000000000005
int MOD = 1000000000 + 7;
int ceil_div(int a, int b) { return a % b == 0 ? a / b : a / b + 1; }
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
void read(vector<int> &a)
{
    for (auto &x : a)
        cin >> x;
}

void solve()
{
    map<string, int> mp;
    vector<string> bitcoin_core = {
        "getblock",
        "getblockchaininfo",
        "getblockcount",
        "getblockfilter",
        "getblockhash",
        "getblockheader",
        "getblockstats",
        "getchaintips",
        "getchaintxstats",
        "getdifficulty",
        "getmemoryinfo",
        "getrpcinfo",
        "help",
        "logging",
        "stop",
        "uptime",
        "generateblock",
        "generatetoaddress",
        "generatetodescriptor",
        "getblocktemplate",
        "getmininginfo",
        "getnetworkhashps",
        "prioritisetransaction",
        "submitblock",
        "submitheader",
        "addnode",
        "clearbanned",
        "disconnectnode",
        "getaddednodeinfo",
        "getconnectioncount",
        "getnettotals",
        "getnetworkinfo",
        "getnodeaddresses",
        "getpeerinfo",
        "listbanned",
        "ping",
        "setban",
        "setnetworkactive",
        "getmempoolancestors",
        "getmempooldescendants",
        "getmempoolentry",
        "getmempoolinfo",
        "getrawmempool",
        "gettxout",
        "gettxoutproof",
        "gettxoutsetinfo",
        "preciousblock",
        "pruneblockchain",
        "savemempool",
        "scantxoutset",
        "verifychain",
        "verifytxoutproof",
        "analyzepsbt",
        "combinepsbt",
        "combinerawtransaction",
        "converttopsbt",
        "createpsbt",
        "createrawtransaction",
        "decodepsbt",
        "decoderawtransaction",
        "decodescript",
        "finalizepsbt",
        "fundrawtransaction",
        "getrawtransaction",
        "joinpsbts",
        "sendrawtransaction",
        "signrawtransactionwithkey",
        "testmempoolaccept",
        "utxoupdatepsbt",
        "createmultisig",
        "deriveaddresses",
        "estimatesmartfee",
        "getdescriptorinfo",
        "getindexinfo",
        "signmessagewithprivkey",
        "validateaddress",
        "verifymessage",
        "abandontransaction",
        "abortrescan",
        "addmultisigaddress",
        "backupwallet",
        "bumpfee",
        "createwallet",
        "dumpprivkey",
        "dumpwallet",
        "encryptwallet",
        "getaddressesbylabel",
        "getaddressinfo",
        "getbalance",
        "getbalances",
        "getnewaddress",
        "getrawchangeaddress",
        "getreceivedbyaddress",
        "getreceivedbylabel",
        "gettransaction",
        "getunconfirmedbalance",
        "getwalletinfo",
        "importaddress",
        "importdescriptors",
        "importmulti",
        "importprivkey",
        "importprunedfunds",
        "importpubkey",
        "importwallet",
        "keypoolrefill",
        "listaddressgroupings",
        "listlabels",
        "listlockunspent",
        "listreceivedbyaddress",
        "listreceivedbylabel",
        "listsinceblock",
        "listtransactions",
        "listunspent",
        "listwalletdir",
        "listwallets",
        "loadwallet",
        "lockunspent",
        "psbtbumpfee",
        "removeprunedfunds",
        "rescanblockchain",
        "send",
        "sendmany",
        "sendtoaddress",
        "sethdseed",
        "setlabel",
        "settxfee",
        "setwalletflag",
        "signmessage",
        "signrawtransactionwithwallet",
        "unloadwallet",
        "upgradewallet",
        "walletcreatefundedpsbt",
        "walletlock",
        "walletpassphrase",
        "walletpassphrasechange",
        "walletprocesspsbt",
    };
    vector<string> bcoin = {
        "stop",
        "getinfo",
        "getmemoryinfo",
        "setloglevel",
        "validateaddress",
        "createmultisig",
        "createwitnessaddress",
        "signmessagewithprivkey",
        "verifymessage",
        "setmocktime",
        "pruneblockchain",
        "invalidateblock",
        "reconsiderblock",
        "getblockchaininfo",
        "getbestblockhash",
        "getblockcount",
        "getblock",
        "getblockbyheight",
        "getblockhash",
        "getblockheader",
        "getchaintips",
        "getdifficulty",
        "getmempoolinfo",
        "getmempoolancestors",
        "getmempooldescendants",
        "getmempoolentry",
        "getrawmempool",
        "prioritisetransaction",
        "estimatefee",
        "estimatepriority",
        "estimatesmartfee",
        "estimatesmartpriority",
        "gettxout",
        "gettxoutsetinfo",
        "getrawtransaction",
        "decoderawtransaction",
        "decodescript",
        "sendrawtransaction",
        "createrawtransaction",
        "signrawtransaction",
        "gettxoutproof",
        "verifytxoutproof",
        "getnetworkhashps",
        "getmininginfo",
        "getwork",
        "getworklp",
        "getblocktemplate",
        "submitblock",
        "verifyblock",
        "setgenerate",
        "getgenerate",
        "generate",
        "generatetoaddress",
        "getconnectioncount",
        "ping",
        "getpeerinfo",
        "addnode",
        "disconnectnode",
        "getaddednodeinfo",
        "getnettotals",
        "getnetworkinfo",
        "setban",
        "listbanned",
        "clearbanned"};

    vector<string> bcoin2 = {
        "stop",
        "help",
        "getblockchaininfo",
        "getbestblockhash",
        "getblockcount",
        "getblock",
        "getblockbyheight",
        "getblockhash",
        "getblockheader",
        "getblockfilter",
        "getchaintips",
        "getdifficulty",
        "getmempoolancestors",
        "getmempooldescendants",
        "getmempoolentry",
        "getmempoolinfo",
        "getrawmempool",
        "gettxout",
        "gettxoutsetinfo",
        "pruneblockchain",
        "verifychain",
        "invalidateblock",
        "reconsiderblock",
        "getnetworkhashps",
        "getmininginfo",
        "prioritisetransaction",
        "getwork",
        "getworklp",
        "getblocktemplate",
        "submitblock",
        "verifyblock",
        "setgenerate",
        "getgenerate",
        "generate",
        "generatetoaddress",
        "estimatefee",
        "estimatepriority",
        "estimatesmartfee",
        "estimatesmartpriority",
        "getinfo",
        "validateaddress",
        "createmultisig",
        "createwitnessaddress",
        "verifymessage",
        "signmessagewithprivkey",
        "setmocktime",
        "getconnectioncount",
        "ping",
        "getpeerinfo",
        "addnode",
        "disconnectnode",
        "getaddednodeinfo",
        "getnettotals",
        "getnetworkinfo",
        "setban",
        "listbanned",
        "clearbanned",
        "getnodeaddresses",
        "getrawtransaction",
        "createrawtransaction",
        "decoderawtransaction",
        "decodescript",
        "sendrawtransaction",
        "signrawtransaction",
        "gettxoutproof",
        "verifytxoutproof",
        "getmemoryinfo",
        "setloglevel",
    };
    for (auto str : bitcoin_core)
        mp[str]++;
    for (auto str : bcoin2)
        mp.erase(str);
    for (auto str : mp)
    {
        string s = "psbt";
        size_t found = str.first.find(s);
        if (found != string::npos)
            continue;
        cout << str.first << endl;
    }
    // debug(mp.size());
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}