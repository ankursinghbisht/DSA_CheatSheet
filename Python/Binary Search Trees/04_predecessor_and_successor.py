"""
Idea:
recursively calling the function, at each call 3 conditions are there:
-if root is NULL, return
-if root is key , right most child of left subtree is predecessor
and left most child of right subtree is successor
-if root<key, set successor as root and call again.
else
    set predecessor as root, and call again
"""


def copy_node(a, b):
    a.key = b.key
    a.left = b.left
    a.right = b.right


# This function finds predecessor and successor of key in BST.
# It sets pre and suc as predecessor and successor respectively
class Solution:
    def findPreSuc(self, root, pre, suc, key):
        if not root:
            return

        # If the key is present at the root
        if root.key == key:
            # the maximum value in the left subtree is the predecessor
            if root.left:
                temp = root.left
                while temp.right:
                    temp = temp.right
                copy_node(pre, temp)

            # the minimum value in the right subtree is the successor
            if root.right:
                temp = root.right
                while temp.left:
                    temp = temp.left
                copy_node(suc, temp)
            return

        # If the key is smaller than the root's key, go to the left subtree
        if root.key > key:
            copy_node(suc, root)
            self.findPreSuc(root.left, pre, suc, key)
        else:  # Go to the right subtree
            copy_node(pre, root)
            self.findPreSuc(root.right, pre, suc, key)


# {
# Driver Code Starts

import queue


# BST Node
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def buildTree(ip):
    # Corner Case
    if len(ip) == 0 or ip[0] == 'N':
        return None

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    q = queue.Queue()
    q.put(root)

    # Starting from the second element
    i = 1
    while not q.empty() and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.get()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.right)

        i += 1

    return root


# Driver program to test above functions
t = int(input())
for _ in range(t):
    s = input()
    root = buildTree(s.split())
    k = int(input())
    pre = Node(None)
    succ = Node(None)
    ob = Solution()
    ob.findPreSuc(root, pre, succ, k)
    if pre.key:
        print(pre.key, end=' ')
    else:
        print(-1, end=' ')
    if succ.key:
        print(succ.key, end=' ')
    else:
        print(-1, end=' ')
    print()

# } Driver Code Ends
