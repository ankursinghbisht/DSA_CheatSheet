"""
Idea:
inserting all elements in a vector & using 2 pointers, one from start and one from mid, appending the answer
"""

from typing import List


class Solution:
    def rearrangeQueue(self, N: int, q: List[int]) -> List[int]:
        # List to store the rearranged elements
        ans, temp = [], []

        # Step 1: Move elements from the queue to a temporary list
        for elem in q:
            temp.append(elem)  # Get and append the front element of the queue to the temporary list

        # Pointers i and j for traversing the temporary list
        i, j = 0, len(temp) // 2

        # Step 2: Rearrange the elements in the temporary list and store in the result list
        while j < len(temp):
            ans.append(temp[i])  # Append the i-th element to the result list
            ans.append(temp[j])  # Append the j-th element to the result list
            i += 1
            j += 1

        # Return the rearranged list
        return ans


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

        q = IntArray().Input(N)

        obj = Solution()
        res = obj.rearrangeQueue(N, q)

        IntArray().Print(res)

# } Driver Code Ends