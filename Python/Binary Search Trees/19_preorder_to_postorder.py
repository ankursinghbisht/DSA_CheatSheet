"""
Idea:
creating a BST using preorder traversal and returning.
"""


# User function Template for python3

class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None


# Function that constructs BST from its preorder traversal.


def insert(root, val):
    if not root:
        return Node(val)
    if val < root.data:
        root.left = insert(root.left, val)
    elif val > root.data:
        root.right = insert(root.right, val)
    return root


def post_order(pre, size) -> Node:
    root = None
    for i in range(size):
        root = insert(root, pre[i])
    return root


# {
# Driver Code Starts
# Initial Template for Python 3

class Node:
    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None


def postOrd(root):
    if not root:
        return
    postOrd(root.left)
    postOrd(root.right)
    print(root.data, end=' ')


if __name__ == '__main__':
    t = int(input())

    for _tcs in range(t):
        size = int(input())
        pre = [int(x) for x in input().split()]

        root = post_order(pre, size)

        postOrd(root)
        print()
# } Driver Code Ends
