"""
Idea:
Using 2 pointers , both with different pace, once one pointer reached head again, slower pointer is at mid
now make 2 different circular LL
"""

# Back-end complete function Template for Python 3




class Solution:
    # Function to split the given circular linked list into 2 halves.
    def splitList(self, head, head1, head2):
        if head == None:  # if the list is empty, return
            return
        fast = head  # initialize fast pointer to head
        slow = head  # initialize slow pointer to head

        # using Floyd's cycle detection algorithm to find the middle node
        while fast.next != head and fast.next.next != head:
            fast = fast.next.next
            slow = slow.next

        # if the list has even number of nodes
        if fast.next.next == head:
            fast = fast.next

        head1 = head  # head1 will point to the first half of the list
        head2 = slow.next  # head2 will point to the second half of the list

        fast.next = slow.next  # adjusting the pointers
        slow.next = head

        return head1, head2



class Node:
    def __init__(self):
        self.data = None
        self.next = None


def printCircularLinkedList(head):
    tmp = head
    while True:
        print(tmp.data, end=" ")
        tmp = tmp.next
        if tmp == head:
            break
    print()


if __name__ == "__main__":
    for i in range(int(input())):
        head = Node()
        head1 = Node()
        head2 = Node()
        tmp = head
        n = int(input())
        for i in input().split():
            tmp.next = Node()
            tmp = tmp.next
            tmp.data = int(i)
        head = head.next
        tmp.next = head
        obj = Solution()
        head1, head2 = obj.splitList(head, head1, head2)
        printCircularLinkedList(head1)
        printCircularLinkedList(head2)

# } Driver Code Ends