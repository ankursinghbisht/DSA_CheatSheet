"""
Idea:
modifying the binary search, by checking if left or right subarray is sorted & contains the element
as at-least one half will be sorted, and checking if element lies there.
"""


class Solution:
    def search(self, nums: list[int], target: int) -> int:
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2

            if nums[mid] == target:
                return mid

            # if left half [low--mid] is sorted
            if nums[low] <= nums[mid]:
                if nums[low] <= target < nums[mid]:  # checking if element lies here in left half
                    high = mid - 1
                else:
                    low = mid + 1

            # if right half [mid--high] is sorted
            else:
                if nums[mid] < target <= nums[high]:  # checking if element lies here in right half
                    low = mid + 1
                else:
                    high = mid - 1

        return -1


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        target = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.search(arr, target))
        tc -= 1
