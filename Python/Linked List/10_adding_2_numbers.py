"""
Idea:
reversing the LL, performing addition element wise & reversing again & returning
"""


class Solution:
    # Function to reverse a linked list.
    def reverse(self, head):
        prev = None
        current = head

        while current is not None:
            next_node = current.next  # Store the next node
            current.next = prev  # Link the current node to the previous one
            prev = current  # Update prev
            current = next_node  # Update current

        return prev

    # Function to add two numbers represented by linked lists.
    def addTwoLists(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1

        # Reverse both input lists
        reversed_l1 = self.reverse(l1)
        reversed_l2 = self.reverse(l2)

        result = Node(0)  # Initialize the result list
        current = result  # Pointer to the current node in the result list
        carry = 0  # Initialize carry to 0

        # Iterate through the reversed input lists and handle carry
        while reversed_l1 or reversed_l2 or carry:
            value1 = reversed_l1.data if reversed_l1 else 0
            value2 = reversed_l2.data if reversed_l2 else 0

            total = value1 + value2 + carry  # Calculate the sum of digits and carry
            carry = total // 10  # Calculate the new carry value

            new_node = Node(total % 10)  # Create a new node with the sum % 10
            current.next = new_node  # Link the new node to the result list
            current = new_node  # Move the current pointer to the new node

            if reversed_l1:
                reversed_l1 = reversed_l1.next
            if reversed_l2:
                reversed_l2 = reversed_l2.next

        result = self.reverse(result.next)  # Reverse the result and return it
        return result


# {
# Driver Code Starts
# Initial Template for Python 3

# Node Class
class Node:
    def __init__(self, data):
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


# prints the elements of linked list starting with head
def printList(n):
    while n:
        print(n.data, end=' ')
        n = n.next
    print()


if __name__ == '__main__':
    for _ in range(int(input())):

        n = int(input())
        arr1 = (int(x) for x in input().split())
        LL1 = LinkedList()
        for i in arr1:
            LL1.insert(i)

        m = int(input())
        arr2 = (int(x) for x in input().split())
        LL2 = LinkedList()
        for i in arr2:
            LL2.insert(i)

        res = Solution().addTwoLists(LL1.head, LL2.head)
        printList(res)
# } Driver Code Ends