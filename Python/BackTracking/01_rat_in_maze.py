"""
Idea:
using recursion to check all states for answers.
marking current location as visited (for not looping in same place) and after exploring all states ,
unmarking the current state.
"""


# User function Template for python3

class Solution:
    def __init__(self):
        self.ans = []

    def solve(self, m, n, x, y, dir):
        # Base case: If the current position is out of bounds or already visited, return
        if x == n or y == n or x < 0 or y < 0 or m[x][y] == 0:
            return

        # Check if the rat has reached the destination
        if x == n - 1 and y == n - 1:
            self.ans.append(dir)  # Store the valid path
            return

        temp = m[x][y]  # Store the value of the current state
        m[x][y] = 0     # Mark the current cell as visited

        # Explore all possible moves (Down, Up, Right, Left)
        self.solve(m, n, x + 1, y, dir + "D")
        self.solve(m, n, x - 1, y, dir + "U")
        self.solve(m, n, x, y + 1, dir + "R")
        self.solve(m, n, x, y - 1, dir + "L")

        m[x][y] = temp  # Reset the value of the state during backtracking

    def findPath(self, m, n):
        dir = ""  # Initialize the path string
        self.solve(m, n, 0, 0, dir)  # Start exploring paths from the top-left corner
        return self.ans  # Return the list of valid paths


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))

        matrix = [[0 for i in range(n[0])] for j in range(n[0])]
        k = 0
        for i in range(n[0]):
            for j in range(n[0]):
                matrix[i][j] = arr[k]
                k += 1
        ob = Solution()
        result = ob.findPath(matrix, n[0])
        result.sort()
        if len(result) == 0:
            print(-1)
        else:
            for x in result:
                print(x, end=" ")
            print()
# } Driver Code Ends
