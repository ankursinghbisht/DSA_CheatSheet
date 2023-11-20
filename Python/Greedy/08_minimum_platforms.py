"""
Idea:
sorting both arrival and departure time in increasing order.
Total platforms at any time can be obtained by subtracting total departures from total arrivals by that time.
"""


# User function Template for python3

class Solution:
    def minimumPlatform(self, arr, dep, n):
        # Sorting both arrival and departure time in sorted order
        arr.sort()
        dep.sort()

        i, j, ans, count = 0, 0, 0, 0

        while i < n and j < n:
            if arr[i] <= dep[j]:  # If arrival time is smaller, i.e. train is arriving (we need a platform)
                count += 1
                i += 1
            else:  # If departure time is smaller, i.e., train is leaving (we don't need a platform)
                j += 1
                count -= 1
            ans = max(count, ans)  # Keeping track of max platforms required

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        arrival = list(map(int, input().strip().split()))
        departure = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.minimumPlatform(n, arrival, departure))
# } Driver Code Ends
