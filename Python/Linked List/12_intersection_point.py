"""
Idea:
Using 2 pointers to traverse the LL,
if a pointer reaches end, make them point the other LL
(they will be equidistant from the intersection point)
so, next time they point the same element, it'll be the intersection point.
"""


# User function Template for python3


# Function to find intersection point in Y shaped Linked Lists.
def intersetPoint(head1, head2):
    ptr1 = head1
    ptr2 = head2

    if ptr1 is None or ptr2 is None:
        return None

    # Traverse through the lists until they reach the intersection node
    while ptr1 != ptr2:
        ptr1 = ptr1.next
        ptr2 = ptr2.next

        # If at any node ptr1 meets ptr2, then it is an intersection node. Return the intersection node.
        if ptr1 == ptr2:
            return ptr1

        # Once both of them go through reassigning, they will be equidistant from the collision point.

        # When ptr1 reaches the end of a list, then reassign it to head2.
        if ptr1 is None:
            ptr1 = head2
        # When ptr2 reaches the end of a list, then redirect it to head1.
        if ptr2 is None:
            ptr2 = head1

    if ptr1 is not None:
        return ptr1.data
    return -1


# {
# Driver Code Starts
# Initial Template for Python 3


import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


# Node Class
class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        temp = None

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_node):
        if self.head is None:
            self.head = new_node
            self.temp = self.head
            return
        else:
            self.temp.next = new_node
            self.temp = self.temp.next


if __name__ == '__main__':
    t = int(input())
    for cases in range(t):
        x, y, z = map(int, input().strip().split())
        a = LinkedList()  # create a new linked list 'a'.
        b = LinkedList()  # create a new linked list 'b'.
        nodes_a = list(map(int, input().strip().split()))
        nodes_b = list(map(int, input().strip().split()))
        nodes_common = list(map(int, input().strip().split()))

        for x in nodes_a:
            node = Node(x)
            a.append(node)  # add to the end of the list

        for x in nodes_b:
            node = Node(x)
            b.append(node)  # add to the end of the list

        for i in range(len(nodes_common)):
            node = Node(nodes_common[i])
            a.append(node)  # add to the end of the list a
            if i == 0:
                b.append(node)  # add to the end of the list b, only the intersection

        print(intersetPoint(a.head, b.head))

# } Driver Code Ends
