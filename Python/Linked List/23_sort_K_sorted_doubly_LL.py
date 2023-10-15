"""
Idea:
Using min heap to store all nodes according to their values, and
popping top priority node and updating its links
"""

# Python implementation to sort a k sorted doubly linked list
import heapq

head = None


# a node of the doubly linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


# function to sort a k sorted doubly linked list
def sortAKSortedDLL(head, k):
    # if list is empty
    if head is None:
        return head

    pq = []

    newHead = None
    last = None

    for i in range(k + 1):
        # push the node
        heapq.heappush(pq, (head.data, head))
        # move to the next node
        head = head.next

    # loop till there are elements in 'pq'
    while len(pq) > 0:

        if newHead is None:
            newHead = heapq.heappop(pq)[1]
            newHead.prev = None

            # 'last' points to the last node of the result sorted list so far
            last = newHead
        else:
            last.next = heapq.heappop(pq)[1]
            last.next.prev = last
            last = last.next

        # if there are more nodes left in the input list
        if head is not None:
            # push the node
            heapq.heappush(pq, (head.data, head))

            # move to the next node
            head = head.next

    # making 'next' of last node point to NULL
    last.next = None

    # new head of the required sorted DLL
    return newHead


# Function to insert a node at the beginning of the Doubly Linked List
def push(new_data):
    global head

    # allocate node
    new_node = Node(new_data)

    # since we are adding at the beginning, prev is always NULL
    new_node.prev = None

    # link the old list of the new node
    new_node.next = head

    # change prev of head node to new node
    if head != None:
        head.prev = new_node

    # move the head to point to the new node
    head = new_node


# Function to print nodes in a given doubly linked list
def printList(head):
    # if list is empty
    if head is None:
        print("Doubly Linked list empty")

    while head is not None:
        print(head.data, end=" ")
        head = head.next


# Driver code
if __name__ == '__main__':
    # Create the doubly linked list:
    # 3<->6<->2<->12<->56<->8
    push(8)
    push(56)
    push(12)
    push(2)
    push(6)
    push(3)

    k = 2

    print("Original Doubly linked list:")
    printList(head)

    sortedDLL = sortAKSortedDLL(head, k)

    print("\nDoubly Linked List after sorting:")
    printList(sortedDLL)

