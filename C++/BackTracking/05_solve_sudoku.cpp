/*
Idea:
trying all possible combinations of valid digit's position, if whole board is valid, returning true
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9


// } Driver Code Ends
class Solution
{
private:
    // Function to check if placing digit d at position (row, col) is valid
    bool isValid(int board[N][N], int row, int col, int d)
    {
        for (int i = 0; i < N; i++)
        {
            // Check the row for duplicate
            if (board[i][col] == d)
                return false;

            // Check the column for duplicate
            if (board[row][i] == d)
                return false;

            // Check the 3x3 subgrid for duplicate
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == d)
                return false;
        }
        return true;
    }

public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here

        // Iterate through each cell in the Sudoku grid
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // If the cell is empty (contains 0)
                if (grid[i][j] == 0)
                {
                    // Try placing digits 1 to 9 in the empty cell
                    for (int d = 1; d <= 9; d++)
                    {
                        // If placing digit d is valid
                        if (isValid(grid, i, j, d))
                        {
                            // Place digit d and recursively try to solve the Sudoku
                            grid[i][j] = d;
                            if (SolveSudoku(grid))
                                return true; // If a solution is found, return true
                            else
                                grid[i][j] = 0; // Backtrack if placing digit d doesn't lead to a solution
                        }
                    }
                    return false; // If no valid digit can be placed in the current cell, backtrack
                }
            }
        }
        return true; // If the entire Sudoku is filled, a solution is found
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here

        // Print the solved Sudoku grid
        if (SolveSudoku(grid))
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    cout << grid[i][j] << " ";
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0;i < 9;i++)
            for (int j = 0;j < 9;j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends