/*
Idea:
using Queue to keep track of all '1'.
'Pushing all neighbor  marked as '0' to queue with distance from element as '1'.
After queue is empty, returning the distance vector
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the distance of the nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();

        // Initialize visited and distance matrices
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        // Queue to perform BFS, where each element is a pair of coordinates and steps
        queue<pair<pair<int, int>, int>> q;

        // Traverse the matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                // Start BFS from cells containing 1
                if (grid[i][j] == 1)
                {
                    q.push({ {i, j}, 0 });  // Push the coordinates and initial steps
                    vis[i][j] = 1;  // Mark the cell as visited
                }
                else
                    vis[i][j] = 0;  // Mark unvisited cells


        // Array to represent the four possible directions: up, right, down, left
        int delrow[] = { -1, 0, +1, 0 };
        int delcol[] = { 0, +1, 0, -1 };

        // Perform BFS until the queue becomes empty
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;  // Set the distance for the current cell

            // Explore all four neighbors
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check for valid unvisited cell within the grid
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;  // Mark the cell as visited
                    q.push({ {nrow, ncol}, steps + 1 });  // Push the coordinates and steps
                }
            }
        }

        // Return the distance matrix
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends