"""
Idea:
finding the node which will new head, now detaching the old links,
 and attaching first part to the last of second part of doubly LL. and updating links and head.
"""


# Python code to rotate doubly linked list by N nodes.
class Node:
    def __init__(self, data):
        self.data = data
        self.pre = None
        self.next = None


class GFG:
    def __init__(self):
        self.head = None

    # Function to insert nodes at the start of the linked list.
    def insertAtHead(self, data):
        n = Node(data)
        if self.head == None:
            self.head = n
            return

        n.next = self.head
        self.head.pre = n
        self.head = n
        return

    # Function to insert nodes at the tail of the linked list.
    def insertAtTail(self, data):
        if self.head == None:
            self.insertAtHead(data)
            return
        temp = self.head
        while temp.next != None:
            temp = temp.next
        n = Node(data)
        temp.next = n
        n.pre = temp
        return

    # Function to print the list.
    def display(self):
        temp = self.head
        while temp != None:
            print(temp.data, "-->", sep="", end="")
            temp = temp.next
        print("NULL")

    # Function to rotate doubly linked list by N nodes.
    def rotateByN(self, pos):
        if pos == 0:
            return

        ptr = self.head
        while pos > 0:  # finding breakpoint of the LL
            ptr = ptr.next
            pos -= 1

        newHead = ptr
        prev = ptr.pre
        prev.next = None

        while ptr.next is not None:  # last node of original LL
            ptr = ptr.next

        ptr.next = self.head  # updating links & head value
        self.head.pre = ptr
        self.head = newHead

    # Driver Code


if __name__ == "__main__":
    list = GFG()
    list.insertAtTail('a')
    list.insertAtTail('b')
    list.insertAtTail('c')
    list.insertAtTail('d')
    list.insertAtTail('e')

    n = 2
    print("Before Rotation : ")
    list.display()
    list.rotateByN(n)
    print("\nAfter Rotation : ")
    list.display()
    print()
