/*
Idea:
using loop to find word which is in dictionary & recursively calling itself for next words till all words match the dictionary
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    set<string> hash; // Set to store valid dictionary words
    vector<string> ans; // Vector to store valid word break combinations

public:
    // Recursive function to find word break combinations
    void solve(string s, int ind)
    {
        if (ind == s.size())
        {
            s.pop_back(); // Remove the trailing space
            ans.push_back(s); // Store the valid word break combination
            return;
        }

        string subS = "";
        for (int i = ind; i < s.size(); ++i)
        {
            subS += s[i]; // Build a substring
            if (hash.find(subS) != hash.end())
            { // Check if the substring is a valid word
                string temp = s;
                temp.insert(i + 1, " "); // Insert a space after the valid word
                solve(temp, i + 2); // Recur to the next position after the inserted space
            }
        }
    }

    // Function to find all valid word break combinations
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        for (auto it : dict)
            hash.insert(it); // Populate the set with valid dictionary words

        solve(s, 0); // Start the recursive search from the beginning of the string
        return ans; // Return the vector containing all valid word break combinations
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0;i < ans.size();i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends