"""
Idea:
Using Modified binary search, finding 1st & last occurrence of a number
-By finding element to left/right even after finding it in 1st try, till corner element is found
"""


class Solution:
    def find_first_occurrence(self, arr, x):
        left, right = 0, len(arr) - 1
        result = -1

        while left <= right:
            mid = left + (right - left) // 2

            if arr[mid] == x:
                result = mid
                right = mid - 1  # Look in the left subarray for the first occurrence
            elif arr[mid] < x:
                left = mid + 1
            else:
                right = mid - 1

        return result

    def find_last_occurrence(self, arr, x):
        left, right = 0, len(arr) - 1
        result = -1

        while left <= right:
            mid = left + (right - left) // 2

            if arr[mid] == x:
                result = mid
                left = mid + 1  # Look in the right subarray for the last occurrence
            elif arr[mid] < x:
                left = mid + 1
            else:
                right = mid - 1

        return result

    def find(self, arr, n, x):
        return self.find_first_occurrence(arr, x), self.find_last_occurrence(arr, x)


t = int(input())
for _ in range(0, t):
    l = list(map(int, input().split()))
    n = l[0]
    x = l[1]
    arr = list(map(int, input().split()))
    ob = Solution()
    ans = ob.find(arr, n, x)
    print(*ans)
