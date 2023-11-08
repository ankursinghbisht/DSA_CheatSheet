"""
Idea:
using 2 vectors to store inorder traversal of both trees,
using 2 pointers ,one from start of one vector, and other on end of another vector.
checking if pair sums to 'x', else updating the pointers.
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
    def inOrder(self, root, v):
        if root:
            self.inOrder(root.left, v)  # Traverse left subtree
            v.append(root.data)  # Store the node data in the list
            self.inOrder(root.right, v)  # Traverse right subtree

    def countPairs(self, root1, root2, x):
        v1 = []  # List to store elements from the first tree
        v2 = []  # List to store elements from the second tree
        self.inOrder(root1, v1)  # Perform inorder traversal on the first tree
        self.inOrder(root2, v2)  # Perform inorder traversal on the second tree

        count = 0  # Variable to keep track of the count of pairs whose sum is x
        i = 0  # Pointer for the first list
        j = len(v2) - 1  # Pointer for the second list

        # Loop through both lists and find pairs whose sum is x
        while i < len(v1) and j >= 0:
            _sum = v1[i] + v2[j]  # Calculate the sum of elements at current pointers
            if _sum == x:  # If the sum is equal to x, increment count and move pointers
                count += 1
                i += 1
                j -= 1
            elif _sum > x:  # If the sum is greater than x, decrement the second list pointer
                j -= 1
            else:  # If the sum is less than x, increment the first list pointer
                i += 1

        return count  # Return the count of pairs whose sum is x


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s1 = input()
        s2 = input()
        root1 = buildTree(s1)
        root2 = buildTree(s2)
        x = int(input())
        ob = Solution()
        print(ob.countPairs(root1, root2, x))
# } Driver Code Ends