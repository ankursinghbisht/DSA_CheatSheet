"""
Idea:
Recursively splitting the Linked List in halves, and performing LL merge in sorted LL. till whole LL is sorted.
"""


# User function Template for python3

class Solution:
    def sortedMerge(self, head1, head2):
        merged = None
        current = None
        t1 = head1
        t2 = head2

        # Determine the head of the merged list.
        if t1.data < t2.data:
            merged = head1
            t1 = t1.next
        else:
            merged = head2
            t2 = t2.next
        current = merged

        # Merge the two lists.
        while t1 and t2:
            if t1.data < t2.data:
                current.next = t1
                t1 = t1.next
            else:
                current.next = t2
                t2 = t2.next
            current = current.next

        # Append any remaining nodes from both lists.
        if t1:
            current.next = t1
        elif t2:
            current.next = t2

        return merged

    def splitLinkedList(self, head):
        if not head or not head.next:
            return head, None

        slow = head
        fast = head
        prev = None

        # Find the middle of the list using slow and fast pointers.
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        # Disconnect the first half from the second half.
        if prev:
            prev.next = None

        return head, slow

    def mergeSort(self, head):
        if not head or not head.next:
            return head

        # Split the list into two halves.
        first_half, second_half = self.splitLinkedList(head)

        # Recursively sort and merge the two halves.
        return self.sortedMerge(self.mergeSort(first_half), self.mergeSort(second_half))


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys


# Contributed by : Nagendra Jha

# Node Class
class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node


# prints the elements of linked list starting with head
def printList(head):
    if head is None:
        print(' ')
        return
    curr_node = head
    while curr_node:
        print(curr_node.data, end=" ")
        curr_node = curr_node.next
    print(' ')


if __name__ == '__main__':
    t = int(input())
    for cases in range(t):
        n = int(input())
        p = LinkedList()  # create a new linked list 'a'.
        nodes_p = list(map(int, input().strip().split()))
        for x in nodes_p:
            p.append(x)  # add to the end of the list

        printList(Solution().mergeSort(p.head))

# } Driver Code Ends
