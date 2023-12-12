"""
Idea:
pushing elements from Array A to stack , and popping elements if top match index element of array B
If stack isn't empty, return false
"""

from typing import List


class Solution:
    def isStackPermutation(self, N: int, A: List[int], B: List[int]) -> int:
        # Create a list to simulate the stack operations
        stack = []

        # Index to keep track of the elements in sequence B
        index = 0

        # Iterate through each element in sequence A
        for elem in A:
            # Push the current element onto the stack
            stack.append(elem)

            # Check if the top of the stack matches the current element in sequence B
            while stack and stack[-1] == B[index]:
                # Pop the element from the stack and move to the next element in sequence B
                stack.pop()
                index += 1

        # If the stack is empty, it means sequences A and B are stack permutations
        if not stack:
            return 1  # Return 1 to indicate true
        else:
            return 0  # Return 0 to indicate false


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
        N = int(input())

        A = IntArray().Input(N)

        B = IntArray().Input(N)

        obj = Solution()
        res = obj.isStackPermutation(N, A, B)

        print(res)

# } Driver Code Ends