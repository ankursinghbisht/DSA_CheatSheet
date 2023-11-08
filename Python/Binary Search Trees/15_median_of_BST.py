"""
Idea:
finding total nodes in BST, then while doing inorder traversal,
find the middle node (element which is in middle when BST is placed in an array.
"""


# Function to count the number of nodes in the binary tree
def countNodes(n):
    # Base case: if node is None, return 0
    if n is None:
        return 0
    # Counting the current node and recursively counting the nodes in the left and right subtrees
    return 1 + countNodes(n.left) + countNodes(n.right)


# Function to find the target node and its value in the binary tree
def find(n, serialNo, target):
    # Base case: if node is None, return the current serial number and 0 as value
    if n is None:
        return (serialNo, 0)

    # Recursively finding the target node in the left subtree  and updating the serial number and value
    serialNo, val = find(n.left, serialNo, target)

    # Incrementing the serial number
    serialNo += 1

    # If the serial number exceeds the target, return the current serial number and value
    if serialNo > target:
        return (serialNo, val)

    # If the serial number is equal to the target, return the current serial number and the node's value
    if serialNo == target:
        return (serialNo, n.data)

    # Recursively finding the target node in the right subtree  and updating the serial number and value
    return find(n.right, serialNo, target)


# Function to find the median of the binary tree
def findMedian(root):
    # Counting the total number of nodes in the tree
    n = countNodes(root)

    # If the total number of nodes is odd, finding the value of the middle node
    if n % 2 == 1:
        return find(root, 0, 1 + n // 2)[1]

    # If the total number of nodes is even, finding the values of the middle two nodes
    else:
        # Finding the values of the two middle nodes
        median = find(root, 0, n // 2)[1] + find(root, 0, 1 + n // 2)[1]
        # Returning the median by dividing the sum by 2
        if median % 2:
            return median / 2
        else:
            return median // 2


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import deque


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


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
    for _ in range(t):
        s = input()
        root = buildTree(s)
        print(findMedian(root))

# } Driver Code Ends