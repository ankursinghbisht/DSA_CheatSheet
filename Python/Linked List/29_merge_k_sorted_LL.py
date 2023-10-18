"""
Idea:
iterating through the array of LLs, merging 2 LLs at a time & updating the head nodes associated in array. returning the last head as answer.
"""


# Back-end complete function Template for Python 3

class Solution:
    # Function to merge two sorted list into one sorted list.
    def MergeLists(self, n1, n2):
        ret = None

        # comparing data in both lists and storing the smaller in result and
        # recursively calling the MergeLists function for next node in result.
        if n2.data < n1.data:
            ret = n2
            n2 = n2.next
        else:
            ret = n1
            n1 = n1.next

        tail = ret

        while n1 is not None and n2 is not None:
            if n2.data < n1.data:
                tail.next = n2
                tail = n2
                n2 = n2.next
            else:
                tail.next = n1
                tail = n1
                n1 = n1.next

        if n1:
            tail.next = n1
        if n2:
            tail.next = n2

        # returning the resultant list.
        return ret

    # Function to merge K sorted linked list.
    def mergeKLists(self, arr, K):
        N = K
        last = N - 1

        while last != 0:
            i = 0
            j = last
            while i < j:
                # calling MergeLists function to merge two different list into
                # one list which has sorted elements.
                arr[i] = self.MergeLists(arr[i], arr[j])

                # going for the next pair of lists.
                i += 1
                j -= 1

                # if all pairs are merged, we update the last.
                if i >= j:
                    last = j

        # returning the merged list.
        return arr[0]


# {
# Driver Code Starts
# Initial Template for Python 3

class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add(self, x):
        if self.head is None:
            self.head = Node(x)
            self.tail = self.head
        else:
            self.tail.next = Node(x)
            self.tail = self.tail.next


def printList(head):
    walk = head
    while walk:
        print(walk.data, end=' ')
        walk = walk.next
    print()


if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        line = [int(x) for x in input().strip().split()]

        heads = []
        index = 0

        for i in range(n):
            size = line[index]
            index += 1

            newList = LinkedList()

            for _ in range(size):
                newList.add(line[index])
                index += 1

            heads.append(newList.head)

        merged_list = Solution().mergeKLists(heads, n)
        printList(merged_list)

# } Driver Code Ends