//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int n;
    vector<vector<int>> dp;
    int recur(vector<int> &a, int i, int j, int k)
    {
        if (i == j)
            return n - 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int diff = a[j] - a[i];
        int ans = INT_MAX;
        if (diff <= k)
            ans = i + n - j;
        else
        {
            ans = min(ans, recur(a, i + 1, j, k));
            ans = min(ans, recur(a, i, j - 1, k));
        }
        return dp[i][j] = ans;
    }
    int removals(vector<int> &a, int k)
    {
        n = a.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        sort(a.begin(), a.end());
        return recur(a, 0, n - 1, k);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int ans = ob.removals(arr, k);

        cout << ans << endl;
    }
}

// } Driver Code Ends