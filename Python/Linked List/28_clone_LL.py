"""
Idea:
iterating LL 3 times:
1st iteration: create copy of a node and append it just after original node.
2nd iteration: create copy of random links as : original->next->arbitrary = original->arbitrary->next
3rd iteration: restoring original and copied LL
"""

# User function Template for python3


class Solution:
    # Function to clone a linked list with next and random pointer.
    def copyList(self, head):
        # code here
        if head is None:
            return None
        # Create new nodes and insert them next to the original nodes
        curr = head
        while curr is not None:
            newNode = Node(curr.data)
            newNode.next = curr.next
            curr.next = newNode
            curr = newNode.next
        # Set the random pointers of the new nodes
        curr = head
        while curr is not None:
            if curr.arb is not None:
                curr.next.arb = curr.arb.next
            curr = curr.next.next
        # Separate the new nodes from the original nodes
        curr = head
        clonedHead = head.next
        clonedCurr = clonedHead
        while clonedCurr.next != None:
            curr.next = curr.next.next
            clonedCurr.next = clonedCurr.next.next
            curr = curr.next
            clonedCurr = clonedCurr.next
        curr.next = None
        clonedCurr.next = None
        return clonedHead


# {
# Driver Code Starts
class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None
        self.arb = None


class LinkedList:
    def __init__(self):
        self.head = None


def insert(tail, data):
    tail.next = Node(data)
    return tail.next


def setarb(head, a, b):
    h = head
    i = 1
    while i < a and h:
        h = h.next
        i += 1
    an = h

    h = head
    i = 1
    while i < b and h:
        h = h.next
        i += 1

    if an:
        an.arb = h


def validation(head, res):
    headp = head
    resp = res

    d = {}

    while head and res:
        if head == res:
            return
        if head.data != res.data:
            return

        if head.arb:
            if not res.arb:
                return

            if head.arb.data != res.arb.data:
                return

        elif res.arb:
            return
        if head not in d:
            d[head] = res
        head = head.next
        res = res.next

    if not head and res:
        return
    elif head and not res:
        return

    head = headp
    res = resp
    while head:
        if head == res:
            return
        if head.arb:
            if head.arb not in d:
                return
            if d[head.arb] != res.arb:
                return
        head = head.next
        res = res.next

    return True


if __name__ == '__main__':
    t = int(input())
    for cases in range(t):
        __n, __m = list(map(int, input().strip().split()))
        __nodes = list(map(int, input().strip().split()))
        __aarb = list(map(int, input().strip().split()))
        __ll = LinkedList()
        __ll2 = LinkedList()
        __ll.head = Node(__nodes[0])
        __ll2.head = Node(__nodes[0])
        __tail = __ll.head
        __tail2 = __ll2.head

        for x in __nodes[1:]:
            __tail = insert(__tail, x)
            __tail2 = insert(__tail2, x)

        for i in range(0, len(__aarb), 2):
            setarb(__ll.head, __aarb[i], __aarb[i + 1])
            setarb(__ll2.head, __aarb[i], __aarb[i + 1])

        obj = Solution()
        __res = obj.copyList(__ll.head)
        if validation(__ll.head, __res) and validation(__ll2.head, __res):
            print(1)
        else:
            print(0)
# } Driver Code Ends
