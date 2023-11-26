"""
Idea:
using priority queue as MinHeap,storing all ropes, and updating PQ after joining of 2 ropes
"""


# Back-end complete function Template for Python 3

class Solution:
    # Function to return the minimum cost of connecting the ropes.
    def minCost(self, a, n):

        # list containing our min heap.
        min_heap = []

        # inserting all elements in heap.
        for num in a:
            heapq.heappush(min_heap, num)

        total_cost = 0

        # using a loop while there is more than one element in min heap.
        while len(min_heap) > 1:
            # storing the first and second numbers from min heap.
            val_1 = heapq.heappop(min_heap)
            val_2 = heapq.heappop(min_heap)

            val = val_1 + val_2

            # adding their sum in result.
            total_cost += val
            # pushing the sum first and second numbers in min heap.
            heapq.heappush(min_heap, val)

        # returning the result.
        return total_cost


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys
import heapq
from collections import defaultdict


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
        ob = Solution()
        print(ob.minCost(a, n))
# } Driver Code Ends