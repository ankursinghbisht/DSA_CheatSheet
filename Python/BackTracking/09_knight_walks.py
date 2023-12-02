"""
Idea:
have 2D array to keep track of visited cells, and using BFS to find the shortest path.
using a queue to store all possible cells of knight. and iterating each till final cell is reached
"""

from collections import deque


class Solution:
    def isValid(self, x, y, N):
        # Check if the position (x, y) is within the bounds of the chessboard (N x N).
        return 0 <= x < N and 0 <= y < N

    def minStepToReachTarget(self, KnightPos, TargetPos, N):
        # Possible moves for the knight.
        dxy = [[2, 1], [2, -1], [-2, 1], [-2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2]]

        # Adjust positions to 0-based indexing.
        KnightPos[0] -= 1
        KnightPos[1] -= 1
        TargetPos[0] -= 1
        TargetPos[1] -= 1

        # Initialize a 2D visited array.
        vis = [[False for i in range(N)] for j in range(N)]

        # Initialize a queue for BFS traversal.
        q = deque()
        q.append([KnightPos[0], KnightPos[1], 0])  # [x, y, steps]
        vis[KnightPos[0]][KnightPos[1]] = True

        # Perform BFS traversal.
        while len(q):
            cur = q.popleft()
            x = cur[0]
            y = cur[1]
            steps = cur[2]

            # Check if the knight has reached the target position.
            if x == TargetPos[0] and y == TargetPos[1]:
                return steps

            # Explore all possible moves from the current position.
            for i in range(8):
                n_x = x + dxy[i][0]
                n_y = y + dxy[i][1]

                # Check if the new position is valid and has not been visited.
                if self.isValid(n_x, n_y, N) and not vis[n_x][n_y]:
                    q.append([n_x, n_y, steps + 1])
                    vis[n_x][n_y] = True

        # If the target position is not reachable, return -1.
        return -1


# {
# Driver Code Starts

T = int(input())
for i in range(T):
    N = int(input())
    KnightPos = list(map(int, input().split()))
    TargetPos = list(map(int, input().split()))
    obj = Solution()
    ans = obj.minStepToReachTarget(KnightPos, TargetPos, N)
    print(ans)

# } Driver Code Ends
