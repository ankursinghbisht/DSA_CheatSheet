"""
Idea:
Iterating each element, and using temporary pointers, reversing the pointer direction
& returning the last element ( as head)
"""




class Solution:
    # Function to reverse a linked list.
    def reverseList(self, head):
        now = head
        prev = None

        while now is not None:
            nxt = now.next
            now.next = prev

            prev = now
            now = nxt

        return prev


class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


def printList(head):
    tmp = head
    while tmp:
        print(tmp.data, end=' ')
        tmp = tmp.next
    print()


if __name__ == '__main__':
    for i in range(int(input())):
        n = int(input())
        arr = [int(x) for x in input().split()]

        lis = Linked_List()
        for i in arr:
            lis.insert(i)

        newHead = Solution().reverseList(lis.head)
        printList(newHead)
