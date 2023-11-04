"""
Idea:
finding the lowest ancestor of 2 desired nodes, and finding distance between the nodes and the ancestor node,
return the sum of distances.
"""

# User function Template for python3



class Solution:
    # Function to return the lowest common ancestor in a Binary Tree.
    def lca(self, root, n1, n2):

        if root is None:
            return None

        # if either n1 or n2 matches with data at current node, we return root.
        # (if a node is ancestor of other, then the ancestor node becomes the lowest common ancestor).
        if root.data == n1 or root.data == n2:
            return root

        # calling the lca function recursively for left and right subtrees.
        left_lca = self.lca(root.left, n1, n2)
        right_lca = self.lca(root.right, n1, n2)

        # if both of the above calls return non-NULL value then one node is present in one subtree and other is present in another subtree.
        # So, this node is the lowest common ancestor.
        if left_lca and right_lca:
            return root

        # else we check if left subtree or right subtree is the lowest common ancestor.
        if left_lca is not None:
            return left_lca
        else:
            return right_lca

    # Returns level of key k if it is present in  tree, otherwise returns -1
    def findLevel(self, root, k, level):
        if root is None:
            return -1
        if root.data == k:
            return level

        left = self.findLevel(root.left, k, level + 1)
        if left == -1:
            return self.findLevel(root.right, k, level + 1)
        return left

    def findDist(self, root, a, b):
        temp = self.lca(root, a, b)
        left = self.findLevel(temp, a, 0)
        right = self.findLevel(temp, b, 0)
        return left + right


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(50000)
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
        a, b = map(int, input().split())
        ob = Solution()
        print(ob.findDist(root, a, b))

# } Driver Code Ends
