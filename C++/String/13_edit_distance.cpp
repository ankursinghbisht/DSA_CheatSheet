/*
Idea:
Using Recursion & Dynamic Programming to calculate the minimum edit distance
(number of insertions, deletions, or substitutions) required to transform one string into another
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int editDistance(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        return minDis(s1, s2, m, n, dp);
    }
    int minDis(string s1, string s2, int n, int m, vector<vector<int> >& dp)
    {

        // If any string is empty, return the remaining characters of other string
        if (n == 0)
            return m;

        if (m == 0)
            return n;

        // To check if the recursive tree for given n & m has already been executed
        if (dp[n][m] != -1)
            return dp[n][m];

        // If characters are equal, execute recursive function for n-1, m-1
        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = minDis(s1, s2, n - 1, m - 1, dp);

        // If characters are not equal, we need to find the minimum cost out of all 3 operations.
        else {
            int insert, del, replace;

            insert = minDis(s1, s2, n, m - 1, dp);
            del = minDis(s1, s2, n - 1, m, dp);
            replace = minDis(s1, s2, n - 1, m - 1, dp);
            return dp[n][m] = 1 + min(insert, min(del, replace));
        }
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
