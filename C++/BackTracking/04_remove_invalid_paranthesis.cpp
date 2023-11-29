/*
Idea:
finding min no. of unwanted brackets, and using backtracking and dp, finding all possible valid strings.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<string, int> dp;  // Memoization table to store intermediate results

    // Helper function to remove invalid parentheses recursively
    int Remove_Invalid_Parentheses(string s, int cnt, set<string>& st)
    {
        // If cnt is 0, it means we have removed the excess parentheses, now check validity
        if (cnt == 0)
        {
            int minr = solve(s);
            // If the string is valid, add it to the result set
            if (minr == 0)
            {
                st.insert(s);
                return 1;
            }
            return 0;
        }

        // If the current string is already in the memoization table, return the result
        if (dp.find(s) != dp.end()) return dp[s];

        // Try removing each parentheses and recurse
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' || s[i] == '(')
            {
                string left = s.substr(0, i);
                string right = s.substr(i + 1);
                dp[left + right] = Remove_Invalid_Parentheses(left + right, cnt - 1, st);
            }
        }

        return dp[s];
    }

    // Helper function to check the minimum number of parentheses needed to make the string valid
    int solve(string s)
    {
        int cnt = 0, n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push('(');
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
    }

public:
    // Main function to remove invalid parentheses
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> v;

        int cnt = solve(s);  // Find the minimum number of parentheses needed to make the string valid
        set<string> st;
        Remove_Invalid_Parentheses(s, cnt, st);  // Remove excess parentheses recursively

        while (!st.empty())
        {
            v.push_back(*st.begin());  // Add valid strings to the result vector
            st.erase(st.begin());
        }
        return v;
    }
};