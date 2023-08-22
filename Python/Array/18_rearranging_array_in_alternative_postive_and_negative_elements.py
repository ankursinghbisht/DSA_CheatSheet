"""

Rule- "not using any extra space"

Idea:

->for naive method:
(preserving the order of elements)
-checking if any element is out of order, and finding the next element to replace it with
& then right rotating array withing those 2 elements, to preserve the order

->efficient method:
(not preserving order of elements)
-shifting all negative elements to right & positive to left, and swapping every other positive element to negative


-> ( if extra space is allowed):
-using extra vector/array, using 2 pointers, one for storing positive& other for negative,
-iterating through original vector/array, placing positive using one point for positive and other for negative
"""


def rotate(ds, low, high):
    i = high
    temp = ds[high]
    while i > low:
        ds[i] = ds[i - 1]
        i -= 1
    ds[i] = temp


def rearrange_naive(arr):
    for i in range(len(arr)):
        if i & 1:  # index is odd(1,3,5), element should be positive
            if arr[i] < 0:
                out_of_place = i
                for k in range(i + 1, len(arr)):
                    if arr[k] >= 0:
                        # index found from where element need to swapped
                        rotate(arr, out_of_place, k)
                        break

        else:  # index is even (0,2,4), element should be negative
            if arr[i] >= 0:
                out_of_place = i
                for k in range(i + 1, len(arr)):
                    if arr[k] < 0:
                        # index found from where element need to swapped
                        rotate(arr, out_of_place, k)
                        break


def rearrange(arr):
    i = 0
    j = len(arr) - 1

    while i < j:
        # swapping all positive elements to left and negative to right
        while arr[i] >= 0 and i < len(arr):
            i += 1
        while arr[j] < 0 <= j:
            j -= 1
        if i < len(arr) and j >= 0 and i < j:
            arr[i], arr[j] = arr[j], arr[i]

    i = 0
    j = len(arr) - 1
    while i < j:
        if not j & 1:  # to check if last element is in right place,
            j -= 1
            # as every other element will be in wrong place, we just need to swap them
        arr[i], arr[j] = arr[j], arr[i]
        i += 2
        j -= 2


def rearrange_with_space(arr):
    temp = arr.copy()
    positive_index = 1
    negative_index = 0

    for i in range(len(arr)):
        # checking if element is positive or negative & storing with respective pointers
        if temp[i] < 0:
            arr[negative_index] = temp[i]
            negative_index += 2
        else:
            arr[positive_index] = temp[i]
            positive_index += 2


if __name__ == "__main__":
    array = [2, 3, -4, -1, 6, -9]

    # rearrange_naive(array)
    rearrange(array)
    # rearrange_with_space(array)
    print("Rearranged array is")
    print(array)
