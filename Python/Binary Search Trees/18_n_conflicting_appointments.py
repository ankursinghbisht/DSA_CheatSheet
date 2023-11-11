"""
Idea:
Idea:
using BST, to keep track of existing appointments with it's range,
if any appointment collides with existing, printing that appointment
and inserting it.
"""


# Python3 program to print all conflicting appointments in a given set of appointments

# Structure to represent an interval
class Interval:

    def __init__(self):
        self.low = None
        self.high = None


# Structure to represent a node in Interval Search Tree
class ITNode:

    def __init__(self):
        self.max = None
        self.i = None
        self.left = None
        self.right = None


def newNode(j):
    # print(j)
    temp = ITNode()
    temp.i = j
    temp.max = j[1]

    return temp


# A utility function to check if given two intervals overlap
def doOVerlap(i1, i2):
    if i1[0] < i2[1] and i2[0] < i1[1]:
        return True

    return False


# Function to create a new node
def insert(node, data):
    global succ

    # If the tree is empty, return a new node
    root = node

    if node is None:
        return newNode(data)

    # If key is smaller than root's key, go to left  subtree and set successor as current node  print(node)
    if data[0] < node.i[0]:

        # print(node)
        root.left = insert(node.left, data)

    # Go to right subtree
    else:
        root.right = insert(node.right, data)
    if root.max < data[1]:
        root.max = data[1]

    return root


# The main function that searches a given interval i in a given Interval Tree.
def overlapSearch(root, i):
    # Base Case, tree is empty
    if root is None:
        return None

    # If given interval overlaps with root
    if doOVerlap(root.i, i):
        return root.i

    # If left child of root is present and
    # max of left child is greater than or equal to given interval,
    # then I may overlap with an interval is left subtree
    if (root.left != None and root.left.max >= i[0]):
        return overlapSearch(root.left, i)

    # Else interval can only overlap with right subtree
    return overlapSearch(root.right, i)


# This function prints all conflicting appointments in a given array of  appointments.
def printConflicting(appt, n):
    # Create an empty Interval Search Tree, add first appointment
    root = None
    root = insert(root, appt[0])

    # Process rest of the intervals
    for i in range(1, n):

        # If current appointment conflicts with any of the existing intervals, print it
        res = overlapSearch(root, appt[i])

        if res is not None:
            print("[", appt[i][0], ",", appt[i][1], "] Conflicts with [", res[0], ",", res[1], "]")

        # Insert this appointment
        root = insert(root, appt[i])


# Driver code
if __name__ == '__main__':
    # Let us create interval tree
    appt = [[1, 5], [3, 7],
            [2, 6], [10, 15],
            [5, 6], [4, 100]]

    n = len(appt)

    print("Following are conflicting intervals")

    printConflicting(appt, n)
