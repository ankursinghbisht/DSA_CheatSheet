"""
Idea:
using Queue to keep track of all '1'.
'Pushing all neighbor  marked as '0' to queue with distance from element as '1'.
After queue is empty, returning the distance vector
"""

from collections import deque


class Solution:
    def nearest(self, grid):
        n = len(grid)
        m = len(grid[0])

        # Initialize visited and distance matrices
        vis = [[0] * m for _ in range(n)]
        dist = [[0] * m for _ in range(n)]

        # Queue to perform BFS, where each element is a tuple of coordinates and steps
        q = deque()

        # Traverse the matrix
        for i in range(n):
            for j in range(m):
                # Start BFS from cells containing 1
                if grid[i][j] == 1:
                    q.append(((i, j), 0))  # Append the coordinates and initial steps
                    vis[i][j] = 1  # Mark the cell as visited
                else:
                    vis[i][j] = 0  # Mark unvisited cells

        # Array to represent the four possible directions: up, right, down, left
        delrow = [-1, 0, 1, 0]
        delcol = [0, 1, 0, -1]

        # Perform BFS until the queue becomes empty
        while q:
            row, col = q[0][0]
            steps = q[0][1]
            q.popleft()

            dist[row][col] = steps  # Set the distance for the current cell

            # Explore all four neighbors
            for i in range(4):
                nrow = row + delrow[i]
                ncol = col + delcol[i]

                # Check for valid unvisited cell within the grid
                if n > nrow >= 0 == vis[nrow][ncol] and 0 <= ncol < m:
                    vis[nrow][ncol] = 1  # Mark the cell as visited
                    q.append(((nrow, ncol), steps + 1))  # Append the coordinates and steps

        # Return the distance matrix
        return dist


# {
# Driver Code Starts

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, m = map(int, input().split())
        grid = []
        for _ in range(n):
            a = list(map(int, input().split()))
            grid.append(a)
        obj = Solution()
        ans = obj.nearest(grid)
        for i in ans:
            for j in i:
                print(j, end=" ")
            print()

# } Driver Code Ends