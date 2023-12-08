"""
Idea:
using stack to keeping track of last encountered element.
Iterating from end to start of array-popping stack element till it's empty of value is greater than current element.
and inserting the element to stack.
"""

# User function Template for python3


from collections import deque


class Solution:
    # Function to find the next greater element for each element of the array.
    def nextLargerElement(self, arr, n):

        s = deque()
        res = [0] * n

        # traversing the array from last element in backward direction.
        for i in range(n - 1, -1, -1):
            # while element at top of stack is less than or equal to current array element, we pop elements
            while len(s) and s[-1] <= arr[i]:
                s.pop()

            # if stack becomes empty, we store -1 in the answer list
            # else we store the top element of the stack.
            if not len(s):
                res[i] = -1
            else:
                res[i] = s[-1]

            # pushing the current array element into the stack.
            s.append(arr[i])

        # returning the list.
        return res


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


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())

        a = list(map(int, input().strip().split()))
        obj = Solution()
        res = obj.nextLargerElement(a, n)
        for i in range(len(res)):
            print(res[i], end=" ")
        print()
# } Driver Code Ends
