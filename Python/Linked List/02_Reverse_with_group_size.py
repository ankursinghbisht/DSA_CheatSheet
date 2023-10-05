"""
Idea:
Using dummy variable to keep track of the head after being sorted.
& reversing the linked list for each group.
"""


class Solution:
    def reverse(self, head, k):
        if not head or k == 1:
            return head

        dummy = Node(-1)
        dummy.next = head

        length = 0
        prev = dummy
        next_node = dummy
        now = dummy

        while now is not None:
            now = now.next  # Finding the length of the linked list
            length += 1

        while next_node:
            now = prev.next
            next_node = now.next  # Setting up variables for each group

            temp_len = min(length-1, k)  # Finding the group length, limited to the target length of k
            for i in range(1, temp_len):
                now.next = next_node.next
                next_node.next = prev.next
                prev.next = next_node
                next_node = now.next  # Reversing the group

            prev = now
            length -= k

        return dummy.next  # Returning the head


# {
# Driver Code Starts
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        # self.tail

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=" ")
            # arr.append(str(temp.data))
            temp = temp.next
        print()


if __name__ == '__main__':
    t = int(input())
    while (t > 0):
        llist = LinkedList()
        n = input()
        values = list(map(int, input().split()))
        for i in reversed(values):
            llist.push(i)
        k = int(input())
        new_head = LinkedList()
        ob = Solution()
        new_head = ob.reverse(llist.head, k)
        llist.head = new_head
        llist.printList()
        t -= 1

# } Driver Code Ends
