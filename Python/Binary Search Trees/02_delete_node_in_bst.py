"""
Idea:
3 cases while delete a node:
- it is a leaf node, delete independently
- has one child, delete node, and replace it with it's child
- has 2 children, finding immediate successor/predecessor, replacing and deleting the original location of successor/predecessor.
"""


class Solution:
    def deleteNode(self, root, key):
        # base case
        if not root:
            return root

        # Recursive calls for ancestors of the node to be deleted
        if root.val < key:
            root.right = self.deleteNode(root.right, key)
            return root
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
            return root

        # reached the node to be deleted
        if not root.left:
            temp = root.right
            del root
            return temp
        elif not root.right:
            temp = root.left
            del root
            return temp
        else:
            parent_of_successor, successor = root, root.right

            # finding the successor
            while successor.left:
                parent_of_successor = successor
                successor = successor.left

            # Delete the successor. Since the successor is always the left child of its parent,
            # we can safely make the successor's right child the left child of its parent.
            # If there is no successor, then assign the successor's right to the parent of the successor's right.
            if parent_of_successor != root:
                parent_of_successor.left = successor.right
            else:
                parent_of_successor.right = successor.right

            # copy the successor's value to the root
            root.val = successor.val

            del successor
            return root
