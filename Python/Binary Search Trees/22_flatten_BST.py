"""
Idea:
using Inorder traversal, in each step, keeping track of previous node,
and updating it's right pointer to current node.
"""

# Python3 implementation of the approach

global prev


# Node of the binary tree
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Function to print flattened binary Tree
def printTree(parent):
    curr = parent
    while curr is not None:
        print(curr.data, end=' ')
        curr = curr.right


# Function to perform in-order traversal recursively
def inorder(curr):
    global prev
    # Base case
    if curr is None:
        return
    inorder(curr.left)
    prev.left = None
    prev.right = curr
    prev = curr
    inorder(curr.right)


# Function to flatten binary tree using level order traversal
def flatten(parent):
    global prev
    # Dummy node
    dummy = node(-1)

    # Pointer to previous element
    prev = dummy

    # Calling in-order traversal
    inorder(parent)

    prev.left = None
    prev.right = None
    ret = dummy.right

    # Delete dummy node
    return ret


# Driver code
if __name__ == '__main__':
    root = node(5)
    root.left = node(3)
    root.right = node(7)
    root.left.left = node(2)
    root.left.right = node(4)
    root.right.left = node(6)
    root.right.right = node(8)

    # Calling required function
    printTree(flatten(root))
