"""
Idea:
Using Recursion & backtracking, with each cell in the matrix. if end is reached, saving it-till all paths are discovered
returning the longest path's length
"""


class Solution:
    def __init__(self):
        # Initialize class variables
        self.row = 0
        self.col = 0
        self.ans = -1

    def solve(self, mat, target_x, target_y, x, y, dist):
        # Base cases for recursion
        if x < 0 or y < 0 or x == self.row or y == self.col or mat[x][y] != 1:
            return
        # Reached the target cell, update the answer
        if x == target_x and y == target_y:
            self.ans = max(self.ans, dist)
            return

        # Mark the current cell as visited
        mat[x][y] = -1

        # Explore all four possible directions
        self.solve(mat, target_x, target_y, x + 1, y, dist + 1)
        self.solve(mat, target_x, target_y, x - 1, y, dist + 1)
        self.solve(mat, target_x, target_y, x, y + 1, dist + 1)
        self.solve(mat, target_x, target_y, x, y - 1, dist + 1)

        # Backtrack: restore the original value of the current cell
        mat[x][y] = 1

    def longestPath(self, mat, n: int, m: int, xs: int, ys: int, xd: int, yd: int) -> int:
        # Set the dimensions of the matrix
        self.row = n
        self.col = m

        # Start the recursive exploration from the source cell
        self.solve(mat, xd, yd, xs, ys, 0)

        # Return the final result
        return self.ans


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

        b = IntArray().Input(4)

        mat = IntMatrix().Input(a[0], a[0])

        obj = Solution()
        res = obj.longestPath(mat, a[0], a[1], b[0], b[1], b[2], b[3])

        print(res)

# } Driver Code Ends