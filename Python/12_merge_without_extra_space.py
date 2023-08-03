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


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a, b = map(int, input().strip().split())
        array1 = list(map(int, input().strip().split()))
        array2 = list(map(int, input().strip().split()))
        merge_with_sorting(array1, array2, a, b)
        print(*array1, end=" ")
        print(*array2)
