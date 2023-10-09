"""
Idea:
Using 2 pointer technique:
front to be moved twice at one iteration & behind to be moved once.
once front reaches end, return value of behind, if null return -1
"""

# your task is to complete this function



class Solution:
    #  Should return data of middle node. If linked list is empty, then  -1
    def findMid(self, head):
        if head is None:
            return None

        ptr1 = head
        ptr2 = head
        while ptr2 is not None and ptr2.next is not None:
            ptr1 = ptr1.next
            # this pointer moves 1 node ahead everytime loop is run

            ptr2 = ptr2.next.next
            # this pointer moves 2 nodes ahead everytime loop is run

        return ptr1.data
        # since slow was moving with half speed, it is there at halfway point


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
        print(ob.findMid(list1.head))

# } Driver Code Ends