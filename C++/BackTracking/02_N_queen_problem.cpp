/*
Idea:
Using recursion to explore each row at a time, within each row ,
checking if a queen can be placed at a certain column and exploring its states.
If all queens can be placed in a board, returning the answer
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
    vector<vector<int>> ans;

public:
    // Function to check if placing a queen in a specific column is possible
    bool isPossible(const vector<int>& vc, int pos)
    {
        int row = static_cast<int>(vc.size()) + 1;

        // Check if the new queen can be placed in the current column without conflicts
        for (int i = 0; i < row - 1; ++i)
            // Check if there is a queen in the same row or diagonals
            if (vc[i] == pos || abs(i - (row - 1)) == abs(vc[i] - pos))
                return false;  // Conflict found


        return true;  // No conflicts found, it's possible to place the queen
    }

    // Recursive function to solve the N-Queens problem
    void solve(int n, int row, int count, vector<int> temp)
    {
        // Base case: If all queens are placed, add the solution to the result
        if (row > n)
        {
            if (count == n)
                ans.push_back(temp);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int i = 1; i <= n; ++i)
            if (isPossible(temp, i))
            {
                temp.push_back(i);  // Place the queen
                solve(n, row + 1, count + 1, temp);  // Recur to the next row
                temp.pop_back();  // Backtrack: remove the queen to explore other possibilities
            }
    }

    // Function to find all solutions to the N-Queens problem
    vector<vector<int>> nQueen(int n)
    {
        vector<int> temp;
        solve(n, 1, 0, temp);  // Start with the first row
        return ans;  // Return the list of solutions
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0;i < ans.size();i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends