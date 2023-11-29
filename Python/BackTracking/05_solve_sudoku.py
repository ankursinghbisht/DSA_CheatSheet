"""
Idea:
trying all possible combinations of valid digit's position, if whole board is valid, returning true
"""


# User function Template for python3

class Solution:
    def __init__(self):
        self.N = 9

    def is_valid(self, board, row, col, d):
        # Function to check if placing digit d at position (row, col) is valid
        for i in range(self.N):
            # Check the row for duplicate
            if board[i][col] == d:
                return False

            # Check the column for duplicate
            if board[row][i] == d:
                return False

            # Check the 3x3 subgrid for duplicate
            if board[3 * (row // 3) + (i // 3)][3 * (col // 3) + (i % 3)] == d:
                return False

        return True

    def SolveSudoku(self, grid):
        # Function to find a solved Sudoku

        # Iterate through each cell in the Sudoku grid
        for i in range(self.N):
            for j in range(self.N):
                # If the cell is empty (contains 0)
                if grid[i][j] == 0:
                    # Try placing digits 1 to 9 in the empty cell
                    for d in range(1, 10):
                        # If placing digit d is valid
                        if self.is_valid(grid, i, j, d):
                            # Place digit d and recursively try to solve the Sudoku
                            grid[i][j] = d
                            if self.SolveSudoku(grid):
                                return True  # If a solution is found, return True
                            else:
                                grid[i][j] = 0  # Backtrack if placing digit d doesn't lead to a solution

                    return False  # If no valid digit can be placed in the current cell, backtrack

        return True  # If the entire Sudoku is filled, a solution is found

    def printGrid(self, grid):
        # Function to print grids of the Sudoku

        # Print the solved Sudoku grid
        if self.SolveSudoku(grid):
            for i in range(self.N):
                for j in range(self.N):
                    print(grid[i][j], end=" ")


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while (t > 0):
        grid = [[0 for i in range(9)] for j in range(9)]
        row = [int(x) for x in input().strip().split()]
        k = 0
        for i in range(9):
            for j in range(9):
                grid[i][j] = row[k]
                k += 1

        ob = Solution()

        if (ob.SolveSudoku(grid) == True):
            ob.printGrid(grid)
            print()
        else:
            print("No solution exists")
        t = t - 1
# } Driver Code Ends