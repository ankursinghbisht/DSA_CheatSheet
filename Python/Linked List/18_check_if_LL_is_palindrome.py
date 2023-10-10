"""
Idea:
splitting the LL into 2 equal halves, if count of elements is odd, middle element will be in both LLs.
Reversing one of the LL, and now comparing each element.
"""


class Solution:
    # solution

    # Function to reverse a linked list.
    def reverseList(self, temp):
        current = temp
        prevNode = None
        nextNode = None

        while current is not None:
            nextNode = current.next
            current.next = prevNode
            prevNode = current
            current = nextNode
        return prevNode

        # Function to return the size of linked list.

    def getSize(self, head):
        count = 0
        curr_node = head
        while curr_node:
            count += 1
            curr_node = curr_node.next
        return count

    # Function to check whether the list is palindrome.
    def isPalindrome(self, head):
        current = head
        flag = True

        # finding number of nodes in the list.
        s = self.getSize(head)
        mid = (s // 2) if (s % 2 == 0) else ((s + 1) // 2)

        # finding the middle node in given singly linked list.
        for i in range(1, mid):
            current = current.next

            # reversing the list after middle node to end.
        revHead = self.reverseList(current.next)

        # comparing nodes of first half and second half of list.
        while head is not None and revHead is not None:
            if head.data != revHead.data:
                flag = False
                break

            head = head.next
            revHead = revHead.next

            # returning 1 if list is palindrome else 0.
        return flag


# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys


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


if __name__ == '__main__':
    t = int(input())
    for cases in range(t):
        n = int(input())
        a = LinkedList()  # create a new linked list 'a'.
        nodes_a = list(map(int, input().strip().split()))
        for x in nodes_a:
            a.append(x)  # add to the end of the list

        if Solution().isPalindrome(a.head):
            print(1)
        else:
            print(0)
# } Driver Code Ends