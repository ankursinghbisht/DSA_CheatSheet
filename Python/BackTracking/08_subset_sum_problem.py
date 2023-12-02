"""
Idea:
Finding total sum of elements, if not even, returning false.
else: (finding elements which sum to half of total sum)
recursively calling the function over each element of array (with 2 conditions-take for sum or leave)
"""


# User function Template for Python3

class Solution:
    # Recursive function to check if it's possible to partition the array equally.
    def solve(self, arr, N, total, index, sum):
        # Base case: if we have reached the end of the array,
        # check if the current sum is equal to the total target sum.
        if index == N:
            return sum == total

        # If the current sum is greater than the total target sum, return false.
        if sum > total:
            return False

        # Recursive call to check if it's possible to partition the array
        # by either including the current element or excluding it.
        return self.solve(arr, N, total, index + 1, sum + arr[index]) or self.solve(arr, N, total, index + 1, sum)

    # Function to check if the array can be partitioned equally.
    def equalPartition(self, N, arr):
        # Calculate the total sum of the array elements.
        total = sum(arr)

        # If the total sum is odd, it's not possible to divide equally.
        if total % 2 != 0:
            return 0

        # Call the recursive function to check if equal partition is possible.
        return 1 if self.solve(arr, N, total // 2, 0, 0) else 0


# {
# Driver Code Starts
# Initial Template for Python3

import sys

input = sys.stdin.readline
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for it in range(N):
            arr[it] = int(arr[it])

        ob = Solution()
        if (ob.equalPartition(N, arr) == 1):
            print("YES")
        else:
            print("NO")
# } Driver Code Ends
