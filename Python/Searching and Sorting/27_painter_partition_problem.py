"""
Idea:
(We've to find the partition which results in lowest subarray sum)
-declaring 2 vars low =max value in array, and high= sum of all elements( as it  is min& max sum of subarray )
-using binary search to assume 'mid' as feasible partition
(if yes, check for smaller partition), else increase the window.
"""


class Solution:
    # Function to check if partition is possible with given sum of subarray
    def isPossible(self, diff, arr):
        count = 1
        total_sum = 0
        for num in arr:
            # If sum above target, assuming it as a partition, & keeping tally of total partition
            if total_sum + num <= diff:
                total_sum += num
            else:
                total_sum = num
                count += 1
        return count

    def minTime(self, arr, n, k):
        low = max(arr)
        high = sum(arr)
        while low < high:
            mid = low + (high - low) // 2
            if self.isPossible(mid, arr) <= k:  # checking if partition is feasible
                high = mid  # if yes, finding smaller partition
            else:
                low = mid + 1  # if no, increasing the ceiling
        return low


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        str = input().split()
        k = int(str[0])
        n = int(str[1])
        arr = input().split()
        for i in range(n):
            arr[i] = int(arr[i])

        ob = Solution()
        print(ob.minTime(arr, n, k))
