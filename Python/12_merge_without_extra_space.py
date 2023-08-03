"""
Idea:
Separating elements which will be in first or second array in final answer,
then sorting individual elements.

Steps (while sorting after separating):
-setting up indices as last element of 1st array and first element of 2nd array
-traversing & swapping elements, if 1st array has larger elements
-sorting arrays

"""


def merge_with_sorting(arr1, arr2, n, m):
    # setting up indices
    i = n - 1
    j = 0
    while i >= 0 and j < m:
        # checking if any element in 1st array is bigger & swapping if any.
        if arr1[i] >= arr2[j]:
            arr1[i], arr2[j] = arr2[j], arr1[i]
        i -= 1
        j += 1

    arr1.sort()
    arr2.sort()


"""
Based on Shell sort (extension of shell sort)
to sort the elements at varying intervals rather than comparing adjacent elements directly

Idea (for not using sorting):
-Assuming both array as single, and finding gap variable as mean of both lengths
-performing following operations till gap =0
    -place pointers, left at 0 and right at left+gap
    -running loop till we reach right to end i.e. n+m
    -checking if right element is smaller & swapping
    -halving the value of gap
"""


# helper function for swapping
def swapIfGreater(arr1, arr2, ind1, ind2):
    if arr1[ind1] > arr2[ind2]:
        arr1[ind1], arr2[ind2] = arr2[ind2], arr1[ind1]


def merge_without_sorting(arr1, arr2, n, m):
    # len of the imaginary single array:
    length = n + m

    # Initial gap:
    gap = (length // 2) + (length % 2)

    while gap > 0:
        # Place 2 pointers:
        left = 0
        right = left + gap
        while right < length:
            if left < n <= right:
                # case 1: left in arr1[]and right in arr2[]
                swapIfGreater(arr1, arr2, left, right - n)
            elif left >= n:
                # case 2: both pointers in arr2[]:
                swapIfGreater(arr2, arr2, left - n, right - n)
            else:
                # case 3: both pointers in arr1[]:
                swapIfGreater(arr1, arr1, left, right)
            left += 1
            right += 1

        if gap == 1:
            break
        # calculate new gap:
        gap = (gap // 2) + (gap % 2)


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a, b = map(int, input().strip().split())
        array1 = list(map(int, input().strip().split()))
        array2 = list(map(int, input().strip().split()))
        merge_without_sorting(array1, array2, a, b)
        print(*array1, end=" ")
        print(*array2)
