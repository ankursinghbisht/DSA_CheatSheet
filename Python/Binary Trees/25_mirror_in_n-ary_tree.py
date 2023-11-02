"""
Idea:
using map of stacks to store edges or tree,iterate 1st array to insert elements
and while iterating in 2nd array, pop if edges as equal from top of stack.
"""


class Solution:
    def checkMirrorTree(self, n, e, A, B):
        # Create a dictionary to store edges for each node in tree A
        mp = {}
        for i in range(0, 2 * e, 2):
            if A[i] in mp:
                mp[A[i]].append(A[i + 1])
            else:
                mp[A[i]] = [A[i + 1]]

        # Check if the representations are mirrors
        for i in range(0, 2 * e, 2):
            # If the top element of the list for B[i] is not equal to B[i+1], they are not mirrors
            if mp[B[i]][-1] != B[i + 1]:
                return 0
            mp[B[i]].pop()  # Remove the last element from the list for B[i]
        return 1  # The representations are mirrors


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, e = map(int, input().split())

        A = list(map(int, input().split()))
        B = list(map(int, input().split()))

        ob = Solution()
        print(ob.checkMirrorTree(n, e, A, B))
# } Driver Code Ends