"""
Idea:
inorder traversal of binary search tree is in sorted order,
finding no. of swaps required to get inorder traversal sorted.
"""
from typing import List


class Solution:
    def __init__(self):
        self.ans = []  # List to store pairs
        self.ind = 0  # Index counter

    # Function to find minimum swaps to sort an array
    def minSwaps(self, n: int, A: List[int]) -> int:
        def helper(ind, n):
            # if index is greater or equal to the size of the list
            if ind >= n:
                return
            # traverse left subtree
            helper(2 * ind + 1, n)
            # append the value and index pair to self.ans
            self.ans.append([A[ind], self.ind])
            self.ind += 1  # increment the index
            # traverse right subtree
            helper(2 * ind + 2, n)

        # perform inorder traversal
        helper(0, n)
        swaps = 0  # initialize swap counter
        self.ans.sort()  # sort the list of pairs

        # iterate through the list and count the swaps
        for i in range(len(self.ans)):
            # if the current index is not equal to the index in the pair
            if i != self.ans[i][1]:
                # continue swapping until the indices match
                while self.ans[i][1] != i:
                    self.ans[self.ans[i][1]], self.ans[i] = self.ans[i], self.ans[self.ans[i][1]]
                    swaps += 1  # increment the swap counter

        return swaps  # return the total number of swaps


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


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        A = IntArray().Input(n)

        obj = Solution()
        res = obj.minSwaps(n, A)

        print(res)

# } Driver Code Ends
