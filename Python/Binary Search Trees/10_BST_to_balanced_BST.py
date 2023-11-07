"""
Idea:
inorder traversal of BST will be in sorted manner,
To find the lowest height BST, inserting node in new BST using modified binary search method.
"""


# User function Template for python3

class Solution:
    def __init__(self):
        self.val = []

    # Perform in-order traversal on the binary tree and store values in a list
    def inOrder(self, root):
        if not root:
            return
        self.inOrder(root.left)  # Traverse left subtree
        self.val.append(root.data)  # Store current node's data
        self.inOrder(root.right)  # Traverse right subtree

    # Create a balanced BST from the sorted values
    def createTree(self, low, high):
        if high < low:  # Base case for recursion
            return None
        ind = low + (high - low) // 2  # Calculate the middle index
        ans = Node(self.val[ind])  # Create a new node with the middle value
        # Recursively build the left and right subtrees
        ans.left = self.createTree(low, ind - 1)
        ans.right = self.createTree(ind + 1, high)
        return ans

    # Function returns the root of the modified BST
    def buildBalancedTree(self, root):
        self.inOrder(root)  # Perform in-order traversal
        ans = self.createTree(0, len(self.val) - 1)  # Create a balanced BST
        return ans


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

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


def height(root):
    if (root == None):
        return 0;
    else:
        lDepth = height(root.left);
        rDepth = height(root.right);
        if (lDepth > rDepth):
            return (lDepth + 1);
        else:
            return (rDepth + 1);


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        ob = Solution()
        new = (ob.buildBalancedTree(root))
        print(height(new))

# } Driver Code Ends