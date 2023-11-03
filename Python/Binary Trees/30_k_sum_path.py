"""
Idea:
using hashmap to store sum of subpaths.
 we check whether the difference between the current running sum and K has occurred before in the tree.
If it has, that means there exists a subpath between the nodes where the sum is K.
"""


# User function Template for python3

class Solution:
    def __init__(self):
        self.hash = {}

    def solve(self, root, k, current_sum):
        if root is None:
            return 0
        c = 0
        current_sum += root.data
        if current_sum - k in self.hash:  # if there exists a path from a node before that sums to 'k'
            c += self.hash[current_sum - k]
        self.hash[current_sum] = self.hash.get(current_sum,
                                               0) + 1  # add current node's data to the sum and modify the map count
        left = self.solve(root.left, k, current_sum)
        right = self.solve(root.right, k, current_sum)
        self.hash[current_sum] -= 1  # remove current sum count from the map
        return c + left + right

    def sumK(self, root, k):
        self.hash = {0: 1}  # initialize the hash with the sum 0
        return self.solve(root, k, 0)


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(100000)
from collections import deque
from collections import defaultdict


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
        d = int(input())
        ob = Solution()
        print(ob.sumK(root, d))

# } Driver Code Ends
