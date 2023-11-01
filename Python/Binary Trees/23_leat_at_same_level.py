"""
Idea:
Iterating the tree, and counting the position of leaf nodes, if any leaf node is not in same depth , return false.
"""

from queue import Queue


class Solution:
    def check(self, root):
        q = Queue()  # Create a queue for level order traversal
        q.put(root)  # Put the root node into the queue

        level = 0  # Initialize the current level
        leafLevel = -1  # Initialize the leaf level as -1 (undefined)

        while not q.empty():  # Continue traversal while the queue is not empty
            n = q.qsize()  # Get the current size of the queue (number of nodes at the current level)
            level += 1  # Increment the level for each iteration

            for _ in range(n):  # Traverse through each node at the current level
                current = q.get()  # Get the front node from the queue

                # If the current node is a leaf node
                if not current.left and not current.right:
                    # If leafLevel is not set, set it to the current level
                    if leafLevel == -1:
                        leafLevel = level
                    # If the current level is not equal to the leaf level, the leaf nodes are not at the same level
                    elif level != leafLevel:
                        return False

                # Put the left child into the queue if it exists
                if current.left:
                    q.put(current.left)

                # Put the right child into the queue if it exists
                if current.right:
                    q.put(current.right)

        return True  # If all leaf nodes are at the same level, return True


# Code here


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


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        if Solution().check(root):
            print(1)
        else:
            print(0)

# } Driver Code Ends
