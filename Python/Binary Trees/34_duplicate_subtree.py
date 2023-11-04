"""
Idea:
using map to store preorder traversal of tree, and returning nodes with more than one occurrence.
"""

# User function Template for python3



class Solution:
    def printAllDups(self, root):
        d = defaultdict(int)

        def dfs(root):
            if not root:
                return "N"
            else:
                # Perform calculations using the node's data and the results of recursive calls to 'dfs'
                ans = ",".join([str(root.data), dfs(root.left), dfs(root.right)])
                # Check if the 'ans' value is present in the unordered_map 'm'
                if d[ans] == 1:
                    # If 'ans' is found in the map, push the current 'root' node to the 'res' vector
                    result.append(root)
                # Increment the count of 'ans' in the unordered_map 'm'
                d[ans] += 1
                return s

        result = []
        dfs(root)
        result.sort(key=lambda x: x.data)
        return result

# code here


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import deque, defaultdict


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


def preord(root):
    if not root:
        return
    print(root.data, end=' ')
    preord(root.left)
    preord(root.right)


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s = input()
        root = buildTree(s)
        ob = Solution()
        res = ob.printAllDups(root)
        for i in res:
            preord(i)
            print()
# } Driver Code Ends