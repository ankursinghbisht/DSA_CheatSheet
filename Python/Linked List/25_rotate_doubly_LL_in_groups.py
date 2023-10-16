"""
Idea:
reversing k nodes at a time, and keeping track of previous node at each group and updating the links.
"""


# Python implementation to reverse a doubly linked list in groups of given size

# Represents a node of doubly linked list.
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


# Function to get a new Node.
def getNode(data):
    # allocating node
    new_node = Node(0)
    new_node.data = data
    new_node.next = new_node.prev = None
    return new_node


# Function to insert a node at the beginning of the doubly linked list.


def push(head, new_node):
    # since we are adding at the beginning, prev is always null.
    new_node.prev = None
    # link the old list of the new node.
    new_node.next = head
    # change prev of head node to new node.
    if head is not None:
        head.prev = new_node
    # move the head to point to the new node.
    head = new_node
    return head


# Function to print nodes in given doubly linked list.


def printList(head):
    while (head):
        print(head.data, end=" ")
        head = head.next


# Function to reverse a doubly linked list in groups of given size.


def revListInGroupOfGivenSize(head, k):
    if head is None:
        return head
    st = head
    globprev, ans = None, None
    while st is not None:
        # Count the number of nodes.
        count = 1
        curr = st
        prev, next_node = None, None
        while curr is not None and count <= k:
            # Reversing k nodes.
            next_node = curr.next
            curr.prev = next_node
            curr.next = prev
            prev = curr
            curr = next_node
            count += 1

        if ans is None:
            ans = prev
            ans.prev = None

        if globprev is None:
            globprev = st

        else:
            globprev.next = prev
            prev.prev = globprev
            globprev = st

        st = curr

    return ans


# Start with the empty list.
head = None

# Create a doubly linked list: 10<->8<->4<->2
head = push(head, getNode(2))
head = push(head, getNode(4))
head = push(head, getNode(8))
head = push(head, getNode(10))

print("Original list:", end=" ")
printList(head)

k = 2

# Reverse doubly linked list in groups of size 'k'
head = revListInGroupOfGivenSize(head, k)

print("\nModified list:", end=" ")
printList(head)
