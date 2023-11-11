"""
Idea:
Iterating the BST, keeping track of the range of the node allowed by its ancestors.
if any node has value of its max and min range, dead end of BST has occurred.
"""


# Your task is to complete this function
# function should return true/false or 1/0
def solve(root, min, max):
    if not root:
        return False

    if min == root.data and max == root.data:
        return True

    return solve(root.left, min, root.data - 1) or solve(root.right, root.data + 1, max)


def is_dead_end(root):
    return solve(root, 1, float('inf'))


# {
# Driver Code Starts
class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None


def insert(root, node):
    if root is None:
        root = node
    else:
        if root.data < node.data:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)
        elif root.data == node.data:
            return
        else:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)


def traverseInorder(root):
    if root is not None:
        traverseInorder(root.left)
        print(root.data, end=" ")
        traverseInorder(root.right)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        root = None
        for j in arr:
            if root is None:
                root = Node(j)
            else:
                insert(root, Node(j))
        if isdeadEnd(root):
            print(1)
        else:
            print(0)
# Contributed by: Harshit Sidhwa

# } Driver Code Ends
