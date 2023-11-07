"""
Idea:
Storing the values of nodes in a list, sorting and using inorder traversal to place values.
"""


# User function Template for python3


class Solution:
    def __init__(self):
        self.values = []
        self.index = 0

    # Perform in-order traversal on the binary tree and store values in a list
    def in_order(self, root):
        if not root:
            return
        self.in_order(root.left)
        self.values.append(root.data)
        self.in_order(root.right)

    # Helper function for in-place modification of the binary tree
    def in_place(self, root):
        if not root:
            return
        self.in_place(root.left)
        root.data = self.values[self.index]
        self.index += 1
        self.in_place(root.right)

    # Function to convert the binary tree to a binary search tree
    def binaryTreeToBST(self, root):
        if not root:
            return None
        self.in_order(root)
        self.values.sort()
        self.in_place(root)
        return root


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import deque


# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    # Corner Case
    if (len(s) == 0 or s[0] == "N"):
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while (size > 0 and i < len(ip)):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if (currVal != "N"):
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if (i >= len(ip)):
            break
        currVal = ip[i]

        # If the right child is not null
        if (currVal != "N"):
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


def printInorder(root):
    if root is None:
        return
    printInorder(root.left)
    print(root.data, end=' ')
    printInorder(root.right)


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        Solution().binaryTreeToBST(root)
        printInorder(root)
        print()
# } Driver Code Ends
