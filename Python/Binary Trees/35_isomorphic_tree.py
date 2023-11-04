"""
Idea:
Using recursion to find if current node value of both trees are equal, if yes, recursively call for 2 conditions:
Option 1: Both left and right subtrees are the same in both trees
Option 2: Left subtree of one tree matches the right subtree of the other, and vice versa
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
    if len(s) == 0 or s[0] == "N":
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
class Solution:
    # Return True if the given trees are isomotphic. Else return False.
    def isIsomorphic(self, root1, root2):
        # code here.# If both roots are None, they are isomorphic
        if not root1 and not root2:
            return True

        # If one root is None and the other is not, they are not isomorphic
        if not root1 or not root2:
            return False

        # If the data of the roots is different, they are not isomorphic
        if root1.data != root2.data:
            return False

        # Check if the trees are isomorphic by comparing the left and right subtrees in different combinations
        option1 = self.isIsomorphic(root1.left, root2.left) and self.isIsomorphic(root1.right, root2.right)
        option2 = self.isIsomorphic(root1.left, root2.right) and self.isIsomorphic(root1.right, root2.left)

        # Check if either of the subtree combinations yields isomorphic trees
        # Option 1: Both left and right subtrees are the same in both trees
        # Option 2: Left subtree of one tree matches the right subtree of the other, and vice versa
        return option1 or option2


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s1 = input()
        s2 = input()
        root1 = buildTree(s1)
        root2 = buildTree(s2)
        if Solution().isIsomorphic(root1, root2):
            print('Yes')
        else:
            print('No')
# } Driver Code Ends