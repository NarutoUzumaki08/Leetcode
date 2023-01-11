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
    /*
        Hint:
            1. First run bfs from all fire points and let them spread out everywhere possible
            2. Do not run multiple BFS, single BFS is good enough
            3. Our target is to find the minimun time for a fire to reach every [cell]
            4. After that we can do binary search on the answer.
            5. [binary search validation function]
                a. We can do another bfs for our protagonist
                b. Now we will know if depending on the current time if we can visite a cell or not
                c. Meaning if a cell gets fired up before we reach there that means we can't go on to that cell.
                d. Need to remember if it is the final cell then it is ok if our protagonist and the fire reaches there at the same time.

    */

#define FastRead                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define ULL unsigned long long
#define LL long long
#define eps 1e-9
#define inf 0x3f3f3f3f
#define INF 2e18
#define all(a) a.begin(), a.end()
#define Unique(a) sort(all(a)), a.erase(unique(all(a)), a.end())
#define ff first
#define ss second
#define Cube(a) ((a) * (a) * (a))
#define Sqr(a) ((a) * (a))
    int n, m;
    int fire_time[300][300];
    int dis[300][300];

    int fx[9] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
    int fy[9] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};

    int invalid(int x, int y, vector<vector<int>> &grid)
    {
        return x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 2;
    }

    void calculate_fire(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> Q;
        memset(fire_time, inf, sizeof fire_time);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    Q.push({i, j});
                    fire_time[i][j] = 0;
                }
            }
        }

        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            int x = cur.ff;
            int y = cur.ss;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + fx[i];
                int ny = y + fy[i];
                if (invalid(nx, ny, grid))
                    continue;
                if (fire_time[nx][ny] > fire_time[x][y] + 1)
                {
                    fire_time[nx][ny] = fire_time[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }

    int minimum_time_to_reach_end(int wait, vector<vector<int>> &grid)
    {
        memset(dis, inf, sizeof dis);
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        dis[0][0] = wait;
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            int x = cur.ff, y = cur.ss;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + fx[i];
                int ny = y + fy[i];
                if (invalid(nx, ny, grid))
                    continue;
                int new_min = min(dis[nx][ny], dis[x][y] + 1);
                if (nx == n - 1 && ny == m - 1 && new_min <= fire_time[nx][ny])
                    return new_min;
                if (new_min >= fire_time[nx][ny])
                    continue;
                if (dis[nx][ny] > dis[x][y] + 1)
                {
                    dis[nx][ny] = dis[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }

        return inf + 1;
    }

    int find_lazyness(vector<vector<int>> &grid)
    {
        if (fire_time[n - 1][m - 1] == inf)
        {
            return minimum_time_to_reach_end(0, grid) < inf ? 1e9 : -1;
        }
        int max_possible = (n * m) + 1;
        int low = 0, high = max_possible, max_wait = -1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (minimum_time_to_reach_end(mid, grid) <= fire_time[n - 1][m - 1])
            {
                low = mid + 1;
                max_wait = mid;
            }
            else
                high = mid - 1;
        }

        return max_wait == max_possible ? 1e9 : max_wait;
    }

    int maximumMinutes(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        calculate_fire(grid);
        // debug fire_time
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cerr << fire_time[i][j] << " ";
            }
            cerr << endl;
        }
        return find_lazyness(grid);
    }
};
int main()
{
    FastRead;
    Solution s;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << s.maximumMinutes(grid) << endl;
    return 0;
}