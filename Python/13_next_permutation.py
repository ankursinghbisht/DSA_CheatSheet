"""
Idea:
Searching the element which is smaller than it's just next one,
and swapping it with the element next bigger than it
-now reversing the array from the point of swapping till last element
"""


def reverseArray(nums, pos):
    i = pos
    j = len(nums) - 1
    while i < j:
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1


def nextPermutation(nums):
    i = len(nums) - 2
    while i >= 0 and nums[i] >= nums[i + 1]:
        # finding the index, where element are in non-descending order
        i -= 1

    if i >= 0:
        j = len(nums) - 1
        while nums[j] <= nums[i]:
            # finding the index to swap with
            j -= 1

        nums[i], nums[j] = nums[j], nums[i]

        # reversing the array, from the index it was swapped till last
        reverseArray(nums, i + 1)
        return
    # swapping incase the permutation was the last actual permutation,
    # as next permutation will be first one.
    reverseArray(nums, 0)


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        array1 = list(map(int, input().strip().split()))
        nextPermutation(array1)
        print(array1)
