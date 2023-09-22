"""
Idea:
sorting the array, iterating the array with 2 indices i=0 & j=1.
take two index variables i and j, and initialize them as 0 and 1 respectively.
Now run a linear loop. If arr[j] – arr[i] is smaller than n, we need to look for greater arr[j], so increment j.
If arr[j] – arr[i] is greater than n,
we need to look for greater arr[i], so increment i.
"""


class Solution:

    def findPair(self, arr, n, difference):
        arr.sort()
        i, j = 0, 1

        while i < n and j < n:
            if i != j and abs(arr[j] - arr[i]) == difference:  # if elements are matched, returning true
                return True
            elif arr[j] - arr[i] < difference:  # if difference is less than 'difference', increasing the front pointer
                j += 1
            else:
                i += 1  # else increasing the back pointer

        return False


if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        L, N = [int(x) for x in input().split()]
        arr = [int(x) for x in input().split()]

        solObj = Solution()

        if solObj.findPair(arr, L, N):
            print(1)
        else:
            print(-1)
