"""
Idea:
using set to store all encountered elements till now, now using 2 loops,
 with each addressing one of 3 required values-searching if 3rd exist in set, if yes add 1 to answer
"""


# User function Template for python3

def countTriplets(head, x):
    # code here
    ans = 0
    visited = set()
    front = head
    while front is not None:
        second = front.next
        while second is not None:
            num = x - front.val - second.val
            if num in visited:  # if 3rd value exist in the set
                ans += 1
            second = second.next
        visited.add(front.data)
        front = front.next
    return ans


# {
# Driver Code Starts
# Initial Template for Python 3

class Node:
    def __init__(self, x):
        self.val = x
        self.nxt = None


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        line = input().strip().split()
        n = int(line[0])
        x = int(line[1])
        line = input().strip().split()

        head = Node(int(line[0]))
        tail = head
        for i in range(1, n):
            tail.nxt = Node(int(line[i]))
            tail = tail.nxt

        print(countTriplets(head, x))

# } Driver Code Ends
