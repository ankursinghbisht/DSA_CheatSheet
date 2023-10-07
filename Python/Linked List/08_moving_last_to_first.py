"""
Idea:
Finding last & 2nd last element of LL
making next of 2nd last NULL & next of last to the head & updating the head
"""


# Python3 code to move the last item to front

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # Function to add a node
    # at the beginning of Linked List
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Function to print nodes in a
    # given linked list
    def printList(self):
        tmp = self.head
        while tmp is not None:
            print(tmp.data, end=", ")
            tmp = tmp.next
        print()

    # Function to bring the last node to the front
    def moveToFront(self):
        temp = self.head
        if temp is None or temp.next is None:
            return
        while temp.next.next is not None:  # finding last & 2nd last element of LL
            temp = temp.next

        exchanged = temp.next  # updating next pointers of acquired pointers
        temp.next = None

        exchanged.next = self.head
        self.head = exchanged # updated head pointer
}

    # Driver's Code


if __name__ == '__main__':
    llist = LinkedList()

    # swap the 2 nodes
    llist.push(5)
    llist.push(4)
    llist.push(3)
    llist.push(2)
    llist.push(1)
    print("Linked List before moving last to front ")
    llist.printList()

    # Function call
    llist.moveToFront()
    print("Linked List after moving last to front ")
    llist.printList()
