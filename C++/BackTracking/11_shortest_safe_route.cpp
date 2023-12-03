/*
Idea:
Updating the matrix with all possible locations not safe(left,right,up & down of 0 )
Applying BFS, using a queue, with location and length of path, returning the first path to the last column, as it will be shortest
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    int row, col;
    void updateVec(vector<vector<int>>& mat)
    {
        for (int i = 0;i < row;++i)
            for (int j = 0;j < col;++j)
                if (mat[i][j] == 0)
                {
                    if (i - 1 >= 0 && mat[i - 1][j])
                        mat[i - 1][j] = -1;
                    if (i + 1 < row && mat[i + 1][j])
                        mat[i + 1][j] = -1;
                    if (j - 1 >= 0 && mat[i][j - 1])
                        mat[i][j - 1] = -1;
                    if (j + 1 < col && mat[i][j + 1])
                        mat[i][j + 1] = -1;
                }


        for (int i = 0;i < row;++i)
            for (int j = 0;j < col;++j)
                if (mat[i][j] == -1)
                    mat[i][j] = 0;

    }


    class Solution
    {
        int row, col;

        // Function to update the matrix based on the given rules
        void updateVec(vector<vector<int>>& mat)
        {
            for (int i = 0; i < row; ++i)
                for (int j = 0; j < col; ++j)
                    if (mat[i][j] == 0)
                    {
                        // Mark neighboring cells as -1
                        if (i - 1 >= 0 && mat[i - 1][j])
                            mat[i - 1][j] = -1;
                        if (i + 1 < row && mat[i + 1][j])
                            mat[i + 1][j] = -1;
                        if (j - 1 >= 0 && mat[i][j - 1])
                            mat[i][j - 1] = -1;
                        if (j + 1 < col && mat[i][j + 1])
                            mat[i][j + 1] = -1;
                    }

            // Reset marked cells to 0
            for (int i = 0; i < row; ++i)
                for (int j = 0; j < col; ++j)
                    if (mat[i][j] == -1)
                        mat[i][j] = 0;
        }

        // Function to explore neighboring cells and enqueue valid ones for BFS
        void explore(vector<vector<int>>& mat, queue<vector<int>>& q, int r, int c, int path)
        {
            if (r >= 0 && r < row && c >= 0 && c < col && mat[r][c] == 1)
            {
                // Enqueue the cell with its coordinates and path length
                vector<int> vc = { r, c, path };
                q.push(vc);
                mat[r][c] = -1; // Mark as visited
            }
        }

    public:
        // Function to find the shortest path from leftmost to rightmost column
        int findShortestPath(vector<vector<int>>& mat)
        {
            row = mat.size();
            col = mat[0].size();

            // Update the matrix using the given rules
            updateVec(mat);

            // Create a queue for BFS
            queue<vector<int>> q;

            // Enqueue all cells in the leftmost column with their path length
            for (int i = 0; i < row; ++i)
                if (mat[i][0] == 1)
                {
                    vector<int> vc = { i, 0, 1 };
                    q.push(vc);
                    mat[i][0] = -1; // Mark as visited
                }

            // Perform BFS
            while (!q.empty())
            {
                vector<int> vc = q.front();
                q.pop();

                int r = vc[0], c = vc[1], path = vc[2];

                // Check if we reached the rightmost column
                if (c == col - 1)
                    return path;

                // Explore neighboring cells
                explore(mat, q, r, c + 1, path + 1);
                explore(mat, q, r, c - 1, path + 1);
                explore(mat, q, r + 1, c, path + 1);
                explore(mat, q, r - 1, c, path + 1);
            }

            // If we reach here, there is no path to the rightmost column
            return -1;
        }
    };


public:
    int findShortestPath(vector<vector<int>>& mat)
    {
        row = mat.size();
        col = mat[0].size();

        updateVec(mat);

        queue<vector<int>> q;
        for (int i = 0;i < row; ++i)
            if (mat[i][0] == 1)
            {
                vector<int> vc = { i,0,1 };
                q.push(vc);
                mat[i][0] = -1;
            }

        // Perform BFS
        while (!q.empty())
        {
            vector <int>vc = q.front();
            q.pop();

            int r = vc[0], c = vc[1], path = vc[2];


            // Check if we reached the rightmost column
            if (c == col - 1)
                return path;

            // Explore neighboring cells
            explore(mat, q, r, c + 1, path + 1);
            explore(mat, q, r, c - 1, path + 1);
            explore(mat, q, r + 1, c, path + 1);
            explore(mat, q, r - 1, c, path + 1);
        }

        // If we reach here, there is no path to the rightmost column
        return -1;

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends