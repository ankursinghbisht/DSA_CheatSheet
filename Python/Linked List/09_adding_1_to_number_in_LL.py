"""
Idea:
reversing the LL, performing addition element wise & reversing again & returning
"""


# Back-end complete function Template for Python 3

class Solution:
    def reverse(self, head):
        # this function reverses the linked list
        prev = None
        current = head

        while current is not None:
            next = current.next  # storing next node
            current.next = prev  # linking current node to previous
            prev = current  # updating prev
            current = next  # updating current

        return prev

    def addOne(self, head):
        head = self.reverse(head)  # reversing list to make addition easy

        current = head
        carry = 1

        while carry:
            current.data += 1  # adding one to current node

            if current.data < 10:
                return self.reverse(head)
                # if no carry we can reverse back list and return it
            else:
                current.data = 0
                # else we continue with taking carry forward

            if current.next is None:
                break
                # if end of list, we break from loop
            else:
                current = current.next
                # else we move to next node

        current.next = Node(1)  # adding new node for the carried 1
        return self.reverse(head)


# {
# Driver Code Starts
# Initial Template for Python 3

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
    def insert(self, value):
        if self.head is None:
            self.head = Node(value)
            self.tail = self.head
        else:
            self.tail.next = Node(value)
            self.tail = self.tail.next


def PrintList(head):
    while head:
        print(head.data, end='')
        head = head.next


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        num = input()
        ll = LinkedList()  # create a new linked list 'll1'.
        for digit in num:
            ll.insert(int(digit))  # add to the end of the list

        resHead = Solution().addOne(ll.head)
        PrintList(resHead)
        print()

# } Driver Code Ends
