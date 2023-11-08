"""
Idea:
Using inOrder traversal of BST,keeping track of no. of nodes visited, once it hits 'k' returning
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
        self.count = 0  # Variable to keep track of count
        self.ans = -1  # Variable to store the answer

    # Recursive function to find the Kth smallest element in the BST
    def solve(self, root):
        if root:
            self.solve(root.left)  # Traverse left subtree
            self.count -= 1  # Decrement count
            if not self.count:  # If count becomes 0, assign the current node's data to ans
                self.ans = root.data
            self.solve(root.right)  # Traverse right subtree

    # Function to find the Kth smallest element in the BST
    def KthSmallestElement(self, root, K):
        self.count = K  # Initialize count to K
        self.solve(root)  # Call the recursive function to find the Kth smallest element
        return self.ans  # Return the Kth smallest element


# code here.

# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        k1 = int(input())
        print(Solution().KthSmallestElement(root, k1))

# } Driver Code Ends