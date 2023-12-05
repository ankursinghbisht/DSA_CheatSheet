"""
Idea:
using Backtracking, exploring each path till end is reached and appended to the answer vector.
"""

from typing import List

class Solution:

    def __init__(self):
        self.num_rows = None
        self.num_cols = None
        self.all_paths = []

    def explore_paths(self, grid: List[List[int]], x: int, y: int, current_path: List[int]):
        # Base case: if current position is out of bounds or cell is blocked, return
        if x == self.num_rows or y == self.num_cols or grid[x][y] < 0:
            return

        # If reached the bottom-right corner, add the current path to the result
        if x == self.num_rows - 1 and y == self.num_cols - 1:
            temp_path = current_path.copy()
            temp_path.append(grid[x][y])
            self.all_paths.append(temp_path)
            return

        # Add the current cell value to the path
        current_path.append(grid[x][y])

        # Mark the current cell as visited
        grid[x][y] *= (-1)

        # Explore paths by moving right and down
        self.explore_paths(grid, x + 1, y, current_path)
        self.explore_paths(grid, x, y + 1, current_path)

        # Backtrack: restore the original value of the current cell and remove it from the path
        grid[x][y] *= (-1)
        current_path.pop()

    def findAllPossiblePaths(self, num_rows: int, num_cols: int, grid: List[List[int]]) -> List[List[int]]:
        self.num_rows = num_rows
        self.num_cols = num_cols
        starting_path = []
        self.explore_paths(grid, 0, 0, starting_path)
        return self.all_paths



# code here


# {
# Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


class IntMatrix:
    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        # matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a = IntArray().Input(2)

        grid = IntMatrix().Input(a[0], a[1])

        obj = Solution()
        res = obj.findAllPossiblePaths(a[0], a[1], grid)

        IntMatrix().Print(res)

# } Driver Code Ends
