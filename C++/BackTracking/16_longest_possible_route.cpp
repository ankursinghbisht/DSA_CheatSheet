/*
Idea:
Using Recursion & backtracking, with each cell in the matrix. if end is reached, saving it-till all paths are discovered
returning the longest path's length
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int row, col, ans = -1;

public:
    // Helper function to recursively explore the matrix and find the longest path
    void solve(vector<vector<int>>& mat, int target_x, int target_y, int x, int y, int dist)
    {
        // Base cases for recursion
        if (x < 0 || y < 0 || x == row || y == col || mat[x][y] != 1)
            return;

        // Reached the target cell, update the answer
        if (x == target_x && y == target_y)
        {
            ans = max(ans, dist);
            return;
        }

        // Mark the current cell as visited
        mat[x][y] = -1;

        // Explore all four possible directions
        solve(mat, target_x, target_y, x + 1, y, dist + 1);
        solve(mat, target_x, target_y, x - 1, y, dist + 1);
        solve(mat, target_x, target_y, x, y + 1, dist + 1);
        solve(mat, target_x, target_y, x, y - 1, dist + 1);

        // Backtrack: restore the original value of the current cell
        mat[x][y] = 1;
    }

    // Main function to find the longest path in the matrix
    int longestPath(vector<vector<int>>& matrix, int xs, int ys, int xd, int yd)
    {
        // Set the dimensions of the matrix
        row = matrix.size();
        col = matrix[0].size();

        // Start the recursive exploration from the source cell
        solve(matrix, xd, yd, xs, ys, 0);

        // Return the final result
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends