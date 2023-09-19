"""
Idea:
using for loop to iterate over each col of matrix of words,
and using recursion for each row
"""

from typing import List


class Solution:
    def solve(self, list, ans, rowVal, str):
        if rowVal == len(list): # base case
            str = str[:-1]
            ans.append([str])
            return
        for i in range(len(list[0])):
            self.solve(list, ans, rowVal + 1, str + list[rowVal][i] + " ")
            # trying each word in a row and calling the function again

    def sentences(self, list: List[List[str]]) -> List[List[str]]:
        ans = []
        self.solve(list, ans, 0, "")
        return ans


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


class StringMatrix:
    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        # matrix input
        for _ in range(n):
            matrix.append([str(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    a = IntArray().Input(2)

    list = StringMatrix().Input(a[0], a[1])

    obj = Solution()
    res = obj.sentences(list)

    StringMatrix().Print(res)

# } Driver Code Ends
