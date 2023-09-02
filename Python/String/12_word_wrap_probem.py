"""
Idea:
Using recursion (on 2 conditions-inserting words in same row OR in next row)
& using Matrix to store state of each word insertion.
"""

class Solution:
    def __init__(self):
        self.mat = [[-1] * 2001 for _ in range(501)]

    def ReccFunction(self, i, remainder, arr, k):
        if i == len(arr):  # Base case
            return 0

        if self.mat[i][remainder] != -1:  # If the case is already explored, return the value
            return self.mat[i][remainder]

        if arr[i] > remainder:
            # If the word can't be inserted into the same line, insert the word in the next line
            ans = (remainder + 1) * (remainder + 1) + self.ReccFunction(i + 1, k - arr[i] - 1, arr, k)
        else:
            # If we can insert the word in the same line, here are 2 cases
            choice1 = self.ReccFunction(i + 1, remainder - arr[i] - 1, arr, k)  # If the word is inserted in the same line
            choice2 = (remainder + 1) * (remainder + 1) + self.ReccFunction(i + 1, k - arr[i] - 1, arr, k)  # If the word is inserted in a new line
            ans = min(choice1, choice2)

        self.mat[i][remainder] = ans  # Store the calculated value for future use
        return self.mat[i][remainder]

    def solveWordWrap(self, nums, k):
        return self.ReccFunction(0, k, nums, k)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        nums = list(map(int, input().split()))
        k = int(input())
        obj = Solution()
        ans = obj.solveWordWrap(nums, k)
        print(ans)
