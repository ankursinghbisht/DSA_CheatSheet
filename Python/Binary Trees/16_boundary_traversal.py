"""
Idea:
finding left boundary nodes, then all bottom boundary leaf nodes, then reverse right boundary nodes.
"""


# User function Template for python3


class Solution:
    # function to check if a node is a leaf node or not
    def isLeaf(self, node):
        if not node.left and not node.right:
            return True
        return False

    # function to find all leaf nodes at the bottom of the tree
    def leafNode(self, root, ans):
        if not root:
            return
        if root.left:
            self.leafNode(root.left, ans)
        if self.isLeaf(root):
            ans.append(root.val)
        if root.right:
            self.leafNode(root.right, ans)

    # function to find all left nodes
    def leftSubTree(self, root, ans):
        if not root:
            return
        if not self.isLeaf(root):
            ans.append(root.val)
        if root.left:
            self.leftSubTree(root.left, ans)
        elif root.right:
            self.leftSubTree(root.right, ans)

    # function to find all right nodes
    def rightSubTree(self, root, ans):
        if not root:
            return
        if root.right:
            self.rightSubTree(root.right, ans)
        elif root.left:
            self.rightSubTree(root.left, ans)
        if not self.isLeaf(root):
            ans.append(root.val)

    # Function to get the boundary traversal of the binary tree
    def boundaryOfBinaryTree(self, root):
        if not root:
            return []
        ans = [root.val]  # Add the root data to the answer
        # Traverse the left subtree
        self.leftSubTree(root.left, ans)
        # Traverse the leaf nodes on the left and right subtrees
        self.leafNode(root.left, ans)
        self.leafNode(root.right, ans)
        # Traverse the right subtree
        self.rightSubTree(root.right, ans)
        return ans  # Return the final boundary traversal


# Code here


# {
# Driver Code Starts
# Initial Template for Python 3

# function should return a list containing the boundary view of the binary tree
# {
#  Driver Code Starts
import sys

import sys

sys.setrecursionlimit(100000)
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


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        obj = Solution()
        res = obj.printBoundaryView(root)
        for i in res:
            print(i, end=" ")
        print('')
# } Driver Code Ends
