/*
Idea:
loop through substrings and recursively calling function after one palindromic substring is found.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    // Store the result of palindromic partitions
    vector<vector<string>> ans;

    // Function to check if a string is palindrome or not
    bool isPalindrome(const string& str)
    {
        int i = 0, j = str.length() - 1;
        while (i < j)
        {
            if (str[i++] != str[j--])
                return false;
        }
        return true;
    }

public:
    // Recursive function to find palindromic partitions
    void solve(const string& str, vector<string>& vc)
    {
        if (str.empty())
        {
            // If the remaining string is empty, add the current partition to the result
            ans.push_back(vc);
            return;
        }

        string s = "";
        for (int i = 0; i < str.size(); ++i)
        {
            s += str[i];
            if (isPalindrome(s))
            {
                // If the current substring is a palindrome, add it to the current partition
                vc.push_back(s);

                // Recursively find partitions for the remaining substring
                solve(str.substr(i + 1), vc);

                // Backtrack: remove the last added substring to explore other possibilities
                vc.pop_back();
            }
        }
    }

    // Function to find all palindromic partitions of a given string
    vector<vector<string>> allPalindromicPerms(const string& S)
    {
        // Initialize the vector to store the current partition
        vector<string> vc;
        // Start the recursive process to find palindromic partitions
        solve(S, vc);
        // Return the final result
        return ans;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;

        cin >> S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends