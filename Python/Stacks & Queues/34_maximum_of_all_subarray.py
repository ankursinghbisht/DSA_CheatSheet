"""
Idea:
Implementing sliding window technique, using Double ended Queue to keep track of the max element positions.
Inserting at the end, such that inserting element is greater than the end.
"""

# User function Template for python3
from collections import deque


class Solution:

    # Function to find maximum of each subarray of size k.
    def max_of_subarrays(self, arr, n, k):

        ans = []
        dq = deque()

        # Process the first window separately
        for i in range(k):
            while dq and arr[i] >= arr[dq[-1]]:
                dq.pop()
            dq.append(i)

        # Process the remaining windows
        for i in range(k, n):
            ans.append(arr[dq[0]])

            # Remove elements that are out of the current window
            while dq and dq[0] <= i - k:
                dq.popleft()

            # Remove smaller elements as they will not be the maximum
            while dq and arr[i] >= arr[dq[-1]]:
                dq.pop()

            dq.append(i)

        # Add the maximum of the last window
        ans.append(arr[dq[0]])

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys
from collections import deque


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
        n, k = map(int, input().strip().split())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        res = ob.max_of_subarrays(arr, n, k)
        for i in range(len(res)):
            print(res[i], end=" ")
        print()
# } Driver Code Ends