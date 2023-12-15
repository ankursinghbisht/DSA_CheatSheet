/*
Idea:
using Queue to keep track of all rotten oranges.
'Pushing all neighbor oranges marked as '1 (good oranges) to queue
and counting total iterations.
At end , if any orange is left as '1', return -1 , else return iteration count
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid)
    {
        // Create a queue to store the position of rotten oranges
        queue<pair<int, int>> q;

        // Get the number of rows and columns in the grid
        int row = grid.size();
        int col = grid[0].size();

        // Initialize counters for fresh oranges and the answer
        int count = 0; // count of fresh oranges
        int ans = 0;   // answer to be returned

        // Iterate through the grid to find rotten and fresh oranges
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 2)
                {
                    // If the orange is rotten, push its position into the queue
                    q.push({ i, j });
                }
                else if (grid[i][j] == 1)
                {
                    // If the orange is fresh, increment the count
                    ++count;
                }
            }
        }

        // Perform BFS to rot adjacent fresh oranges
        while (!q.empty())
        {
            int size = q.size();
            int flag = 0; // Flag to check if any orange was rotten in this iteration

            // Process all oranges at the current level
            for (int i = 0; i < size; i++)
            {
                // Get the position of the current orange
                int n = q.front().first;
                int m = q.front().second;
                q.pop();

                // Define directions for adjacent cells (up, right, down, left)
                int dx[4] = { -1, 0, 1, 0 };
                int dy[4] = { 0, 1, 0, -1 };

                // Check adjacent cells and rot fresh oranges
                for (int j = 0; j < 4; j++)
                {
                    int nrow = n + dx[j];
                    int ncol = m + dy[j];

                    // Check if the adjacent cell is within bounds and contains a fresh orange
                    if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && grid[nrow][ncol] == 1)
                    {
                        // Rot the fresh orange, decrement the count, push its position to the queue
                        grid[nrow][ncol] = 2;
                        --count;
                        q.push({ nrow, ncol });
                        flag = 1; // Set flag to indicate that an orange was rotten in this iteration
                    }
                }
            }

            // If any orange was rotten in this iteration, increment the answer
            if (flag == 1)
                ++ans;
        }

        // If there are remaining fresh oranges, return -1 (impossible to rot all oranges)
        if (count)
            return -1;

        // Return the minimum time required to rot all oranges
        return ans;
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
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends