"""
Idea:
using BST: inserting value from vector backwards,as nodes. & keeping track of each node's successor
"""

from typing import List


# Define the Node class for the binary search tree
class Node:
    def __init__(self, val):
        self.data = val  # Initialize the data for the node
        self.left = None  # Initialize the left child as None
        self.right = None  # Initialize the right child as None


# Define the insert function to insert nodes into the binary search tree
def insert(root, val, succ):
    if root is None:
        root = Node(val)  # Create a new node if the root is None
        return root

    if root.data > val:
        succ[0] = root  # Set the current node as the successor
        root.left = insert(root.left, val, succ)  # Recursively insert into the left subtree
    elif root.data <= val:
        root.right = insert(root.right, val, succ)  # Recursively insert into the right subtree

    return root  # Return the root of the updated tree


# Define the Solution class to find the least greater element in the array
class Solution:
    def findLeastGreater(self, n, arr):
        root = None  # Initialize the root of the binary search tree as None
        ans = [-1] * n  # Initialize the answer array with -1 for all elements

        # Traverse the array in reverse order
        for i in range(n - 1, -1, -1):
            succ = [None]  # Initialize the successor as None
            root = insert(root, arr[i], succ)  # Insert the current element into the binary search tree
            if succ[0] is not None:
                ans[i] = succ[0].data  # If successor exists, update the answer array

        return ans  # Return the answer array containing the least greater elements


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

        arr = IntArray().Input(n)

        obj = Solution()
        res = obj.findLeastGreater(n, arr)

        IntArray().Print(res)

# } Driver Code Ends
