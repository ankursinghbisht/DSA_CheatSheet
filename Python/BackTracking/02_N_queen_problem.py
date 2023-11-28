"""
Idea:
Using recursion to explore each row at a time, within each row ,
checking if a queen can be placed at a certain column and exploring its states.
If all queens can be placed in a board, returning the answer
"""


# User function Template for python3

class Solution:
    def __init__(self):
        self.ans = []

    # Function to check if placing a queen in a specific column is possible
    def isPossible(self, vc, pos):
        row = len(vc) + 1

        # Check if the new queen can be placed in the current column without conflicts
        for i in range(row - 1):
            # Check if there is a queen in the same row or diagonals
            if vc[i] == pos or abs(i - (row - 1)) == abs(vc[i] - pos):
                return False  # Conflict found

        return True  # No conflicts found, it's possible to place the queen

    # Recursive function to solve the N-Queens problem
    def solve(self, n, row, count, temp):
        # Base case: If all queens are placed, add the solution to the result
        if row > n:
            if count == n:
                self.ans.append(temp[:])  # Use a copy to avoid modifying the original list
            return

        # Try placing a queen in each column of the current row
        for i in range(1, n + 1):
            if self.isPossible(temp, i):
                temp.append(i)  # Place the queen
                self.solve(n, row + 1, count + 1, temp)  # Recur to the next row
                temp.pop()  # Backtrack: remove the queen to explore other possibilities

    # Function to find all solutions to the N-Queens problem
    def nQueen(self, n):
        temp = []
        self.solve(n, 1, 0, temp)  # Start with the first row
        return self.ans  # Return the list of solutions


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        ans = ob.nQueen(n)
        if len(ans) == 0:
            print("-1")
        else:
            for i in range(len(ans)):
                print("[", end="")
                for j in range(len(ans[i])):
                    print(ans[i][j], end=" ")
                print("]", end=" ")
            print()

# } Driver Code Ends
