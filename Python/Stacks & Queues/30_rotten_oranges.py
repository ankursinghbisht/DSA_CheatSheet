"""
Idea:
using Queue to keep track of all rotten oranges.
'Pushing all neighbor oranges marked as '1 (good oranges) to queue
and counting total iterations.
At end , if any orange is left as '1', return -1 , else return iteration count
"""

from collections import deque


class Solution:
    def orangesRotting(self, grid):
        # Create a queue to store the position of rotten oranges
        q = deque()

        # Get the number of rows and columns in the grid
        row, col = len(grid), len(grid[0])

        # Initialize counters for fresh oranges and the answer
        count = 0  # count of fresh oranges
        ans = 0  # answer to be returned

        # Iterate through the grid to find rotten and fresh oranges
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 2:
                    # If the orange is rotten, append its position to the queue
                    q.append((i, j))
                elif grid[i][j] == 1:
                    # If the orange is fresh, increment the count
                    count += 1

        # Perform BFS to rot adjacent fresh oranges
        while q:
            size = len(q)
            flag = 0  # Flag to check if any orange was rotten in this iteration

            # Process all oranges at the current level
            for _ in range(size):
                # Get the position of the current orange
                n, m = q.popleft()

                # Define directions for adjacent cells (up, right, down, left)
                dx = [-1, 0, 1, 0]
                dy = [0, 1, 0, -1]

                # Check adjacent cells and rot fresh oranges
                for j in range(4):
                    nrow, ncol = n + dx[j], m + dy[j]

                    # Check if the adjacent cell is within bounds and contains a fresh orange
                    if 0 <= nrow < row and 0 <= ncol < col and grid[nrow][ncol] == 1:
                        # Rot the fresh orange, decrement the count, append its position to the queue
                        grid[nrow][ncol] = 2
                        count -= 1
                        q.append((nrow, ncol))
                        flag = 1  # Set flag to indicate that an orange was rotten in this iteration

            # If any orange was rotten in this iteration, increment the answer
            if flag == 1:
                ans += 1

        # If there are remaining fresh oranges, return -1 (impossible to rot all oranges)
        if count:
            return -1

        # Return the minimum time required to rot all oranges
        return ans


# {
# Driver Code Starts

T = int(input())
for i in range(T):
    n, m = map(int, input().split())
    grid = []
    for _ in range(n):
        a = list(map(int, input().split()))
        grid.append(a)
    obj = Solution()
    ans = obj.orangesRotting(grid)
    print(ans)

# } Driver Code Ends
