"""
Idea:
keeping 2 pointers , each for odd and even numbers, and appending odd after even ones and returning
"""



class Solution:
    def divide(self, N, head):
        # Initializing odd and even linked lists
        odd = node()
        even = node()
        ptrODD = odd
        ptrEVEN = even
        temp = head

        # Segregating even and odd nodes
        while temp:
            if temp.data % 2 == 1:  # If node is odd
                ptrODD.next = temp
                ptrODD = ptrODD.next
            else:  # If node is even
                ptrEVEN.next = temp
                ptrEVEN = ptrEVEN.next
            temp = temp.next

        # Setting the last node of the odd list to None
        ptrODD.next = None

        # Combining the even and odd lists and returning the head of the even list
        ptrEVEN.next = odd.next
        return even.next


# code here


# {
# Driver Code Starts
# Initial Template for Python3

# Node Class
class node:
    def __init__(self):
        self.data = None
        self.next = None


# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        if self.head == None:
            self.head = node()
            self.tail = self.head
            self.head.data = data
        else:
            new_node = node()
            new_node.data = data
            new_node.next = None
            self.tail.next = new_node
            self.tail = self.tail.next


def printlist(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print('')


# Driver Program
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        list1 = Linked_List()
        n = int(input())
        values = list(map(int, input().strip().split()))
        for i in values:
            list1.insert(i)
        ob = Solution()
        newhead = ob.divide(n, list1.head)
        printlist(newhead)

# } Driver Code Ends