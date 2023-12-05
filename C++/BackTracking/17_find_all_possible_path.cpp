/*
Idea:
using Backtracking, exploring each path till end is reached and appended to the answer vector.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> all_paths;

    void explore_paths(vector<vector<int>>& grid, int x, int y, vector<int> current_path) {
        // Base case: if current position is out of bounds or cell is blocked, return
        if (x == num_rows || y == num_cols || grid[x][y] < 0) {
            return;
        }

        // If reached the bottom-right corner, add the current path to the result
        if (x == num_rows - 1 && y == num_cols - 1)
        {
            current_path.push_back(grid[x][y]);
            all_paths.push_back(current_path);
            return;
        }

        // Add the current cell value to the path
        current_path.push_back(grid[x][y]);

        // Mark the current cell as visited
        grid[x][y] *= (-1);

        // Explore paths by moving right and down
        explore_paths(grid, x + 1, y, current_path);
        explore_paths(grid, x, y + 1, current_path);

        // Backtrack: restore the original value of the current cell and remove it from the path
        grid[x][y] *= (-1);
    }

public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>>& grid) {
        num_rows = n;
        num_cols = m;
        vector<int> starting_path;
        explore_paths(grid, 0, 0, starting_path);
        return all_paths;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends