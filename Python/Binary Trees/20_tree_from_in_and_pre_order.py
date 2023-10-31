"""
Idea:
Finding elements from preorder traversal.
Check the element in preorder traversal,left part will be left subtree, right part will be right subtree.
Recursively calling the function for left and right parts.
"""


# User function Template for python3


class Solution:
    def __init__(self):
        self.pre_index = 0

    # Helper function to construct the tree
    def pre_tree(self, in_order, pre_order, low, high):
        if low > high:
            return None

        # Create a new node using the current element in the preorder traversal
        root = Node(pre_order[self.pre_index])
        self.pre_index += 1

        # Find the index of the current element in the inorder traversal
        in_index = in_order.index(root.data)

        # Construct left and right subtrees recursively
        root.left = self.pre_tree(in_order, pre_order, low, in_index - 1)
        root.right = self.pre_tree(in_order, pre_order, in_index + 1, high)

        return root

    def buildtree(self, in_order, pre_order, n):
        return self.pre_tree(in_order, pre_order, 0, n - 1)


class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None


def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=' ')


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        inorder = [int(x) for x in input().split()]
        preorder = [int(x) for x in input().split()]

        root = Solution().buildtree(inorder, preorder, n)
        printPostorder(root)
        print()

# } Driver Code Ends
