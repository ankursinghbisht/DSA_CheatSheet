"""
Idea:
For BST< root node should be smaller than right child and greater than left.
We traverse tree in bottom up manner. For every traversed node,
we return maximum and minimum values in subtree rooted with it
"""

#User function Template for python3
class Solution:
    class Info:
        def __init__(self, sz, minimum, maximum, ans, isBST):
            self.sz = sz  # Size of subtree
            self.min = minimum  # Min value in subtree
            self.max = maximum  # Max value in subtree
            self.ans = ans  # Size of the largest BST which is a subtree of the current node
            self.isBST = isBST  # If the subtree is a BST

    def largestBSTBT(self, root):
        # Base cases: When the tree is empty or has one child
        if not root:
            return self.Info(0, float('inf'), float('-inf'), 0, True)
        if not root.left and not root.right:
            return self.Info(1, root.data, root.data, 1, True)

        # Recur for left and right subtrees
        l = self.largestBSTBT(root.left)
        r = self.largestBSTBT(root.right)

        # Create a return variable and initialize its size
        ret = self.Info(1 + l.sz + r.sz, 0, 0, 0, False)

        # If the whole tree rooted under the current root is a BST
        if l.isBST and r.isBST and l.max < root.data < r.min:
            ret.min = min(l.min, root.data)
            ret.max = max(r.max, root.data)

            # Update the answer for the tree rooted under the current 'root'
            ret.ans = l.ans + r.ans + 1
            ret.isBST = True
            return ret

        # If the whole tree is not a BST, return the maximum of left and right subtrees
        ret.ans = max(l.ans, r.ans)
        ret.isBST = False

        return ret

    def largestBst(self, root):
        return self.largestBSTBT(root).ans

#{
 # Driver Code Starts
import sys
sys.setrecursionlimit(1000000)

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
    while size > 0 and i < len(ip):
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
        ob = Solution()
        print(ob.largestBst(root))

# } Driver Code Endsw