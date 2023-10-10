"""
Idea:
-Deletion:
deleting the node, while keeping the connections same & special case for head node .
-Reversing:
Reversing each node, and updating each connection.
"""

# Function to reverse a circular linked list
def reverse(head):
    # Check if the list is empty or has only one node
    if head is None or head.next == head:
        return head

    # Initialize pointers
    prev = None
    current = head
    next_node = None

    # Traverse through the list and reverse the pointers
    while current.next != head:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node

    # Reverse the last node
    current.next = prev

    # Update the head to the last node
    head = prev

    return head  # Return the modified head



# Function to delete a node from the circular linked list
def deleteNode(head, data):
    # If the list has only one node, return
    if head is None or head.next == head:
        return

    # Creating a temporary node
    temp = head

    # Deleting the head node
    if data == head.data:
        temp = head
        while temp.next != head:
            temp = temp.next
        head = head.next
        temp.next = head
    # Deleting a node other than the head node
    else:
        temp = head
        while temp.next.data != data:
            temp = temp.next
        temp.next = temp.next.next

#{
 # Driver Code Starts
#Initial Template for Python 3

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def push(data, prev):
    if prev == None:
        prev = Node(data)
        return prev
    tmp = Node(data)
    prev.next = tmp
    return tmp

def printList(head):
    flg = False
    tmp = head
    while flg== False or tmp!=head:
        flg = True
        print(tmp.data, end=" ")
        tmp = tmp.next
    print()

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        arr = [int(i) for i in input().split()]
        delNode = int(input())

        head = Node(None)
        prev = head
        for i in arr:
            prev = push(i, prev)
        head = head.next
        prev.next = head
        deleteNode(head, delNode)
        reverse(head)
        printList(head)

# } Driver Code Ends