/*
Idea:
iterating a string & comparing with each character of other string, if equal adds one to answer
& using DP to keep track of comparisons
*/


#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.

    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // vector to store comparison vaues
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};


int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;          // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

