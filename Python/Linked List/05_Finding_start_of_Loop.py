"""
Idea:
Use  Floyd’s Cycle detection algorithm to detect if a loop is present in linked list
Once detected, finding length of the loop, and setting 2 pointers at head & other to k nodes after head
Incrementing both with same pace till both equal, ( we found the start of loop)
"""

# User function Template for python3


class Solution:
    # Function to find first node if the linked list has a loop.
    def findFirstNode(self, head):
        front, back = head.next, head
        while front != back:
            if front is None or front.next is None: # finding if there's a loop in LL
                return -1
            front = front.next.next
            back = back.next

        ptr1, ptr2 = back.next, back
        length = 1

        # Finding count of elements in the loop
        while ptr1 != ptr2:
            length += 1
            ptr1 = ptr1.next

        ptr1 = ptr2 = head
        for i in range(length):
            ptr2 = ptr2.next  # Setting up 2 pointers (one at head & other to k nodes after head)

        while ptr1 != ptr2:
            # Move both pointers at the same pace; they will meet at the loop starting node
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        return ptr1.data

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

        print(Solution().findFirstNode(LL.head))
# } Driver Code Ends