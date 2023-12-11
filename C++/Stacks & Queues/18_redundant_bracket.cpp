/*
Idea:
pushing opening bracket and operators in a stack.
While encountering closed brackets, if top element is opening bracket-then there is redundancy
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
int checkRedundancy(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            st.push(s[i]);

        else if (s[i] == ')')
        {
            // Check for redundancy when encountering ')'
            if (st.top() == '(')
                return 1; // Redundant expression found

            // Pop operators until '(' is found
            while (!st.empty() && st.top() != '(')
                st.pop();

            // Remove the '(' from the stack
            st.pop();
        }
    }

    return 0; // No redundancy found
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {


        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;

    }
}

// } Driver Code Ends