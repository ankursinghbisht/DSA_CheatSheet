"""
Idea:
sorting in ascending order, and adding difference in each corresponding pair
"""


class Solution:
    # Function to find the minimum sum of absolute differences of two arrays.
    def findMinSum(self, A, B, N):
        sum = 0
        # sorting both arrays in ascending order.
        A.sort()
        B.sort()
        # iterating over both arrays to calculate the sum of absolute differences.
        for i in range(0, N):
            sum += abs(A[i] - B[i])

        return sum


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().strip().split()))
        B = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMinSum(A, B, N)
        print(ans)
# } Driver Code Ends
