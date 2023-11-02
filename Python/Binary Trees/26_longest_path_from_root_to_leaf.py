"""
Idea:
keeping track of the longest path and the height sum in longest path, and recursively iterating the tree to find the deepest node.
"""

# User function Template for python3

class Solution:
    def SumOfLongRootToLeafPathUtil(self, root, Sum, Len, maxLen, maxSum):
        # if true, then we have traversed a
        # root to leaf path
        if (not root):
            # update maximum Length and maximum Sum
            # according to the given conditions
            if (maxLen[0] < Len):
                maxLen[0] = Len
                maxSum[0] = Sum
            elif (maxLen[0] == Len and
                  maxSum[0] < Sum):
                maxSum[0] = Sum
            return

        # recur for left subtree
        self.SumOfLongRootToLeafPathUtil(root.left, Sum + root.data,
                                         Len + 1, maxLen, maxSum)

        # recur for right subtree
        self.SumOfLongRootToLeafPathUtil(root.right, Sum + root.data,
                                         Len + 1, maxLen, maxSum)

    def sumOfLongRootToLeafPath(self, root):
        # if tree is NULL, then Sum is 0
        if (not root):
            return 0
        maxSum = [-999999999999]
        maxLen = [0]

        # finding the maximum Sum 'maxSum' for
        # the maximum Length root to leaf path
        self.SumOfLongRootToLeafPathUtil(root, 0, 0, maxLen, maxSum)

        # required maximum Sum
        return maxSum[0]


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import deque


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


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


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s = input()
        root = buildTree(s)
        ob = Solution()
        res = ob.sumOfLongRootToLeafPath(root)
        print(res)
# } Driver Code Ends