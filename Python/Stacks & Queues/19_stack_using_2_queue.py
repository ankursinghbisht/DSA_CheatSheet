"""
Idea:
Insertion: Inserting all elements in another queue, inserting at end and copying back in original queue
Deletion: deleting from start of queue
"""


# Back-end complete function Template for Python 3


# Function to push an element into stack using two queues.
def push(x):
    global queue_1
    global queue_2

    # second queue is empty, and we push the given number into second queue.
    queue_2.append(x)

    # while first queue is not empty, we keep popping the front element
    # from first queue and storing that element in second queue.
    while len(queue_1):
        # pushing front element into second queue.
        queue_2.append(queue_1[0])

        # popping element from first queue.
        queue_1.pop(0)

    # transferring all elements from queue 2 to queue 1, by swapping the names.
    queue_1, queue_2 = queue_2, queue_1


def pop():
    global queue_1
    global queue_2

    # if first queue is not empty, then we can pop an element.
    if len(queue_1):
        # returning the popped element.
        return queue_1.pop(0)

    # else we return -1.
    else:
        return -1


# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys


_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


queue_1 = []  # first queue
queue_2 = []  # second queue

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int, input().strip().split()))
        i = 0
        while i < len(a):
            if a[i] == 1:
                push(a[i + 1])
                i += 1
            else:
                print(pop(), end=" ")
            i += 1

        # clear both the queues
        queue_1 = []
        queue_2 = []
        print()
# } Driver Code Ends