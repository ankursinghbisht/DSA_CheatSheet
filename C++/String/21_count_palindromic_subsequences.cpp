/*
Idea: using DP to store preprocessed values,
with each iteration, checking if current elements are equal, checking for next elements
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long int mod = 1000000007;
    long long int add(long long int x, long long int y) {
        return ((x % mod) + (y % mod)) % mod;
    }
    long long int sub(long long int x, long long int y) {
        return ((x % mod) - (y % mod) + mod) % mod;
    }
    long long int  countPS(string str)
    {
        long long int  N = str.length();

        // create a 2D array to store the count of palindromic subsequence
        long long int  cps[N + 1][N + 1];
        memset(cps, 0, sizeof(cps));

        // palindromic subsequence of length 1
        for (long long int i = 0; i < N; i++)
            cps[i][i] = 1;

        // check subsequence of length L is palindrome or not
        for (long long int L = 2; L <= N; L++)
        {
            for (long long int i = 0; i <= N - L; i++)
            {
                long long int  k = L + i - 1;
                if (str[i] == str[k])
                    cps[i][k] = add(cps[i][k - 1], add(cps[i + 1][k], 1)) % mod;
                else
                    cps[i][k] = add(cps[i][k - 1], sub(cps[i + 1][k], cps[i + 1][k - 1])) % mod;
            }
        }

        // return total palindromic subsequence
        return cps[0][N - 1] % mod;
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends