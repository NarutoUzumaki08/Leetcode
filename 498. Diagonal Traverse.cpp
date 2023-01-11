//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool check(int n, int m, int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<int> downwardDigonal(int N, vector<vector<int>> a)
    {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        int turn = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j])
                    continue;
                vector<int> temp;
                int x = i, y = j;
                while (check(n, m, x, y))
                {
                    temp.push_back(a[x][y]);
                    vis[x][y] = 1;
                    x++, y--;
                }
                if (turn)
                {
                    reverse(temp.begin(), temp.end());
                    turn = 0;
                }
                else
                    turn = 1;
                for (auto x : temp)
                    ans.push_back(x);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends