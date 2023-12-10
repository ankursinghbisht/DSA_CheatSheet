"""
Idea:
using 2 pointers from start and end, if start knows end , i.e start is not celebrity else end is not celebrity.
iterating til only 1 person left & then rechecking if every person knows the potential celebrity.
"""

# User function Template for python3

from typing import List


class Solution:
    def celebrity(self, M: List[List[int]], n: int) -> int:
        # Initialize pointers for start and end of the party attendees.
        start, end = 0, n - 1

        # Iterate until there is only one person left.
        while start < end:
            # If M[start][end] is 0, it means start knows end, so move end to the left.
            if M[start][end] == 0:
                end -= 1
            # If M[start][end] is 1, it means start doesn't know end, so move start to the right.
            else:
                start += 1

        # The remaining person at 'start' could be a potential celebrity.
        candidate = start

        # Check if the potential celebrity is indeed a celebrity.
        for i in range(n):
            # If the potential celebrity knows anyone, or someone doesn't know the potential celebrity, return -1.
            if M[candidate][i] != 0 or (i != start and M[i][candidate] != 1):
                return -1

        # Return the index of the potential celebrity.
        return candidate


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().strip().split()))
        k = 0
        m = []
        for i in range(n):
            row = []
            for j in range(n):
                row.append(a[k])
                k += 1
            m.append(row)
        ob = Solution()
        print(ob.celebrity(m, n))
# } Driver Code Ends
