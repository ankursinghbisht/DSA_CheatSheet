"""
Idea:
using 2 pointer approach, one from start and one from end,
 checking if both makes the target value, else updating the pointers
"""

from typing import Optional

from typing import List


class Solution:
    def findPairsWithGivenSum(self, target: int, head: Optional['Node']) -> List[List[int]]:
        # code here
        ans = []
        front = back = head
        while back.next is not None:
            back = back.next

        while front != back and back.next != front:
            if front.data + back.data == target:
                ans.append([front.data, back.data])
                front = front.next
                back = back.prev
            elif front.data + back.data < target:  # if sum < target, incrementing the front pointer
                front = front.next
            else:  # if sum > target, incrementing the front pointer
                back = back.prev
        return ans


# {
# Driver Code Starts
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class doublyLL:
    def __init__(self):
        self.head = None

    def insert(self, tail, data):
        head = self.head

        node = Node(data)

        if not head:
            self.head = node
            return node

        tail.next = node
        node.prev = tail
        return node


def displayList(head):
    while head:
        print(head.data, end=' ')
        pvs = head
        head = head.next
    print()

    while pvs:
        print(pvs.data, end=' ')
        pvs = pvs.prev


if __name__ == '__main__':
    tcs = int(input())

    for _ in range(tcs):
        target = int(input())
        n = int(input())
        arr = [int(x) for x in input().split()]

        dll = doublyLL()

        tail = None

        for nodeData in arr:
            tail = dll.insert(tail, nodeData)

        obj = Solution()
        ans = obj.findPairsWithGivenSum(target, dll.head)
        if (len(ans) == 0):
            print(-1)
        else:

            for i in range(len(ans)):
                print("(" + str(ans[i][0]) + "," + str(ans[i][1]) + ")", end=' ')

            print()

# } Driver Code Ends
