"""
Idea:
Updating the matrix with all possible locations not safe(left,right,up & down of 0 )
Applying BFS, using a queue, with location and length of path, returning the first path to the last column, as it will be shortest
"""

from typing import List


class Solution:
    def __init__(self):
        self.row = 0
        self.col = 0

    # Function to update the matrix based on the given rules
    def updateVec(self, mat: List[List[int]]) -> None:
        for i in range(self.row):
            for j in range(self.col):
                if mat[i][j] == 0:
                    # Mark neighboring cells as -1
                    if i - 1 >= 0 and mat[i - 1][j]:
                        mat[i - 1][j] = -1
                    if i + 1 < self.row and mat[i + 1][j]:
                        mat[i + 1][j] = -1
                    if j - 1 >= 0 and mat[i][j - 1]:
                        mat[i][j - 1] = -1
                    if j + 1 < self.col and mat[i][j + 1]:
                        mat[i][j + 1] = -1

        # Reset marked cells to 0
        for i in range(self.row):
            for j in range(self.col):
                if mat[i][j] == -1:
                    mat[i][j] = 0

    # Function to explore neighboring cells and enqueue valid ones for BFS
    def explore(self, mat: List[List[int]], q: List[List[int]], r: int, c: int, path: int) -> None:
        if 0 <= r < self.row and 0 <= c < self.col and mat[r][c] == 1:
            # Enqueue the cell with its coordinates and path length
            vc = [r, c, path]
            q.append(vc)
            mat[r][c] = -1  # Mark as visited

    # Function to find the shortest path from leftmost to rightmost column
    def findShortestPath(self, mat: List[List[int]]) -> int:
        self.row = len(mat)
        self.col = len(mat[0])

        # Update the matrix using the given rules
        self.updateVec(mat)

        # Create a list for BFS
        q = []

        # Enqueue all cells in the leftmost column with their path length
        for i in range(self.row):
            if mat[i][0] == 1:
                vc = [i, 0, 1]
                q.append(vc)
                mat[i][0] = -1  # Mark as visited

        # Perform BFS
        while q:
            vc = q.pop(0)

            r, c, path = vc

            # Check if we reached the rightmost column
            if c == self.col - 1:
                return path

            # Explore neighboring cells
            self.explore(mat, q, r, c + 1, path + 1)
            self.explore(mat, q, r, c - 1, path + 1)
            self.explore(mat, q, r + 1, c, path + 1)
            self.explore(mat, q, r - 1, c, path + 1)

        # If we reach here, there is no path to the rightmost column
        return -1


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

        mat = IntMatrix().Input(a[0], a[1])

        obj = Solution()
        res = obj.findShortestPath(mat)

        print(res)

# } Driver Code Ends