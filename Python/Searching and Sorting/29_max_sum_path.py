"""
Idea:
using 2 arrays holding sum of elements till the pointers
-at intersection (no. at indices being equal) , changing sum of both arrays to the max
-if any array ends, adding rest of elements till both ends.
returning max value
"""


class Solution:
    def maxSumPath(self, arr1, arr2, m, n):
        sum1 = sum2 = 0
        i = j = 0
        while i < m and j < n:
            if arr1[i] == arr2[j]:
                sum1 = sum2 = max(sum1, sum2)+arr1[i]
                i += 1
                j += 1
            elif arr1[i] < arr2[j]:
                sum1 += arr1[i]
                i += 1
            else:
                sum2 += arr2[j]
                j += 1
        while i < m:
            sum1 += arr1[i]
            i += 1
        while j < n:
            sum2 += arr2[j]
            j += 1
        return max(sum1, sum2)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        m, n = list(map(int, input().strip().split()))
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        print(Solution().maxSumPath(arr1, arr2, m, n))
