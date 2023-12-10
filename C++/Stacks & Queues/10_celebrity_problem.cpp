/*
Idea:
using 2 pointers from start and end, if start knows end , i.e start is not celebrity else end is not celebrity.
iterating til only 1 person left & then rechecking if every person knows the potential celebrity.
*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n)
    {
        // Initialize pointers for start and end of the party attendees.
        int start = 0, end = n - 1;

        // Iterate until there is only one person left.
        while (start < end)
        {
            // If M[start][end] is 0, it means start knows end, so move end to the left.
            if (M[start][end] == 0)
                end--;
            // If M[start][end] is 1, it means start doesn't know end, so move start to the right.
            else
                start++;
        }

        // The remaining person at 'start' could be a potential celebrity.
        int candidate = start;

        // Check if the potential celebrity is indeed a celebrity.
        for (int i = 0; i < n; i++)
        {
            // If the potential celebrity knows anyone, or someone doesn't know the potential celebrity, return -1.
            if (M[candidate][i] != 0 || (i != start && M[i][candidate] != 1))
                return -1;
        }

        // Return the index of the potential celebrity.
        return candidate;
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
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;

    }
}

// } Driver Code Ends