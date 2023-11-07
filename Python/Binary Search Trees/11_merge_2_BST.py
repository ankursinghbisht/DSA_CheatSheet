"""
Idea:
using 2 vectors to store inorder traversal of both BST,and merging 2 sorted arrays and returning.
"""

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


# } Driver Code Ends
# User function Template for python3



class Solution:
    def __init__(self):
        self.merged_list = []

    # Perform in-order traversal on the binary tree and store values in a list
    def in_order(self, root, arr):
        if not root:
            return
        self.in_order(root.left, arr)  # Traverse left subtree
        arr.append(root.data)  # Store current node's data
        self.in_order(root.right, arr)  # Traverse right subtree

    # Function to return a list of integers denoting the node values of both the BSTs in a sorted order
    def merge(self, root1, root2):
        v1, v2 = [], []
        self.in_order(root1, v1)
        self.in_order(root2, v2)

        i, j = 0, 0
        while i < len(v1) and j < len(v2):
            if v1[i] <= v2[j]:
                self.merged_list.append(v1[i])
                i += 1
            else:
                self.merged_list.append(v2[j])
                j += 1

        # Append the remaining elements
        while i < len(v1):
            self.merged_list.append(v1[i])
            i += 1
        while j < len(v2):
            self.merged_list.append(v2[j])
            j += 1

        return self.merged_list


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s1 = input()
        s2 = input()
        root1 = buildTree(s1)
        root2 = buildTree(s2)
        res = Solution().merge(root1, root2)
        for i in range(len(res)):
            print(res[i], end=" ")
        print()
# } Driver Code Ends