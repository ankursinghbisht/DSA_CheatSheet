"""
Methodology :
similar to quick sort, but here pivot point's value is set as 0.
swapping all elements greater than 0 to negative elements, till both pointers cross, i.e. array is solved
"""


def negativeToLeft(arr):
    # array is passed as reference, that's why there is no return function

    length = len(arr)
    i = 0
    j = length - 1
    while i < j:
        if arr[i] >= 0 > arr[j]:
            # swap
            arr[i], arr[j] = arr[j], arr[i]

        while arr[i] < 0 and i < length:
            # checking if element on left side are negative, and moving on to next one
            i += 1

        while arr[j] >= 0 and j >= 0:
            # checking if element on right side are positive, and moving on to previous one
            j -= 1


if __name__ == '__main__':

    array = [-1, 2, -3, 4, 5, 6, -7, 8, 9]
    negativeToLeft(array)
    print(array)
