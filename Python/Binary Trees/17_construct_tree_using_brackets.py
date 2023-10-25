"""
Idea:
extracting the number from string,  & recursively calling the function -
for '(' bracket, go to child of current node, and for')', returning the current node.
"""

from typing import Optional
from collections import deque


class Solution:
    def construct_tree(self, s, start):
        # Assuming there is/are no negative  character/characters in the string
        if len(s) == 0 or start[0] >= len(s):
            return None

        # constructing a number from the continuous digits
        num = 0
        while start[0] < len(s) and s[start[0]] != '(' and s[start[0]] != ')':
            num = num * 10 + int(s[start[0]]) - int('0')
            start[0] += 1

        # creating a node from the constructed number from  above loop
        root = None
        if num > 0:
            root = Node(num)

        # As soon as we see first right parenthesis from the current node we start to construct the tree in the left
        if start[0] < len(s) and s[start[0]] == '(':
            start[0] += 1
            root.left = self.construct_tree(s, start)
        if start[0] < len(s) and s[start[0]] == ')':
            start[0] += 1
            return root

        # As soon as we see second right parenthesis from the current node we start to construct the tree in the right
        if start[0] < len(s) and s[start[0]] == '(':
            start[0] += 1
            root.right = self.construct_tree(s, start)
        if start[0] < len(s) and s[start[0]] == ')':
            start[0] += 1

        return root

    def treeFromString(self, s: str) -> Optional['Node']:
        start = [0]
        return self.construct_tree(s, start)


# code here


# {
# Driver Code Starts
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
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


def inputTree():
    treeString = input().strip()
    root = buildTree(treeString)
    return root


def inorder(root):
    if (root == None):
        return
    inorder(root.left);
    print(root.data, end=" ")
    inorder(root.right)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = (input())

        obj = Solution()
        res = obj.treeFromString(s)

        inorder(res)
        print()

# } Driver Code Ends
