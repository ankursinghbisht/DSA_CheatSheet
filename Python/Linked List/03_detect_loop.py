"""
Idea:
using 2 pointers (one with one increment at a time & other with 2 increments),
idea being, if there's a loop in the linked list, they will be pointing at same element once.
"""


class Solution:
    # Function to check if the linked list has a loop.
    def detectLoop(self, head):
        if head is None:
            return False
        front, back = head.next, head

        while (front != back):
            if front is None or front.next is None:
                return False
            front = front.next.next
            back = back.next
        return True


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
    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next

    # connects last node to node at position pos from begining.
    def loopHere(self, pos):
        if pos == 0:
            return

        walk = self.head
        for i in range(1, pos):
            walk = walk.next

        self.tail.next = walk


if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())

        LL = LinkedList()
        for i in input().split():
            LL.insert(int(i))

        LL.loopHere(int(input()))

        print(Solution().detectLoop(LL.head))
# } Driver Code Ends
