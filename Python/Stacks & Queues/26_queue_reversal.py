"""
Idea:
Popping front element, recursing in rest of queue, and inserting the element again.
"""


# User function Template for python3

class Solution:
    def rev(self, q):
        # Base case: if the queue is empty, return an empty queue
        if not q:
            return Queue()

        # Recursive case: remove the front element
        front_element = q.get()
        # Recursively reverse the remaining queue
        reversed_queue = self.rev(q)

        # Insert the front element at the rear
        reversed_queue.put(front_element)

        return reversed_queue


# {
# Driver Code Starts

# Initial Template for Python 3

from queue import Queue

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        q = Queue(maxsize=n)
        for j in a:
            q.put(j)

        ob = Solution()
        q = ob.rev(q)
        for i in range(0, n):
            print(q.get(), end=" ")
        print()
# } Driver Code Ends