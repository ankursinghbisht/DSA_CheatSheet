"""
Idea:
Use  Floyd’s Cycle detection algorithm to detect if a loop is present in linked list
Once detected, finding length of the loop, and setting 2 pointers at head & other to k nodes after head
Incrementing both with same pace till both equal, ( we found the start of loop) & now finding last node & edit it
"""


class Solution:
    # Function to remove a loop in the linked list.
    class Solution:
        # Function to remove a loop in the linked list.
        def ifLoop(self, node_in_loop, head):
            ptr1, ptr2 = node_in_loop.next, node_in_loop
            length = 1

            # Finding count of elements in the loop
            while ptr1 != ptr2:
                length += 1
                ptr1 = ptr1.next

            ptr1 = ptr2 = head
            for i in range(length):
                ptr2 = ptr2.next  # Setting up 2 pointers (one at head & other to k nodes after head)

            while ptr1 != ptr2:
                # Move both pointers at the same pace; they will meet at the loop starting node
                ptr1 = ptr1.next
                ptr2 = ptr2.next

            while ptr1 != ptr2.next:
                # Getting a pointer to the last node
                ptr2 = ptr2.next

            ptr2.next = None

        # Function to check if there's a loop in the linked list
        def removeLoop(self, head):
            front, back = head.next, head
            while front != back:
                if front is None or front.next is None:
                    return
                front = front.next.next
                back = back.next
            self.ifLoop(back, head)


# code here
# remove the loop without losing any nodes


# {
# Driver Code Starts
# driver code:

class Node:
    def __init__(self, val):
        self.next = None
        self.data = val


class linkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add(self, num):
        if self.head is None:
            self.head = Node(num)
            self.tail = self.head
        else:
            self.tail.next = Node(num)
            self.tail = self.tail.next

    def isLoop(self):
        if self.head is None:
            return False

        fast = self.head.next
        slow = self.head

        while slow != fast:
            if fast is None or fast.next is None:
                return False
            fast = fast.next.next
            slow = slow.next

        return True

    def loopHere(self, position):
        if position == 0:
            return

        walk = self.head
        for _ in range(1, position):
            walk = walk.next
        self.tail.next = walk

    def length(self):
        walk = self.head
        ret = 0
        while walk:
            ret += 1
            walk = walk.next
        return ret


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = tuple(int(x) for x in input().split())
        pos = int(input())

        ll = linkedList()
        for i in arr:
            ll.add(i)
        ll.loopHere(pos)

        Solution().removeLoop(ll.head)

        if ll.isLoop() or ll.length() != n:
            print(0)
            continue
        else:
            print(1)

# } Driver Code Ends
