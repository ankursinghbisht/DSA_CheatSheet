"""
Idea:
using level order, but with 2 stacks, traversing with one stack and inserting child in another one.
"""

# User function Template for python3



class Solution:
    # Function to store the zig zag order traversal of tree in a list.
    def zigZagTraversal(self, root):
        res = []

        # if root is None, we return the list.
        if not root:
            return res

        # declaring two stacks to store the current and new level.
        current_level, next_level = [root], []
        left_to_right = True

        while current_level:
            # storing the top element of current_level stack in temp and popping it.
            temp = current_level.pop()

            # if temp is not None, we store the data at temp in the list.
            if temp:
                res.append(temp.data)

                # if left_to_right is True, it stores nodes from left to right, else from right to left in next_level stack.
                if left_to_right:
                    if temp.left:
                        next_level.append(temp.left)
                    if temp.right:
                        next_level.append(temp.right)
                else:
                    if temp.right:
                        next_level.append(temp.right)
                    if temp.left:
                        next_level.append(temp.left)

            # if current_level stack is empty, left_to_right is flipped to change the order of storing the nodes, and both stacks are swapped.
            if not current_level:
                left_to_right = not left_to_right
                current_level, next_level = next_level, current_level

        # returning the list.
        return res

# {
# Driver Code Starts
# Initial Template for Python 3


from collections import defaultdict
from collections import deque


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


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


if __name__ == '__main__':
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        ob = Solution()
        res = ob.zigZagTraversal(root)
        for i in range(len(res)):
            print(res[i], end=" ")
        print()
# } Driver Code Ends