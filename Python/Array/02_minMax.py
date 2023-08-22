def findMinMax(arr):
    # finding min & max elements of array
    length = len(arr)
    if len == 1:
        # array is of size 1
        return arr[0], arr[0]
    minVal = arr[0]
    maxVal = arr[0]

    # finding min & max
    for i in range(1, length):
        maxVal = max(maxVal, arr[i])
        minVal = min(minVal, arr[i])

    return minVal, maxVal


def recurrMinMax(arr, start, end):
    if start == end:
        # only 1 element in list
        return arr[start], arr[start]
    elif end - start == 1:
        # only 2 elements, then compare and return
        return (arr[start], arr[end]) if arr[start] < arr[end] else (arr[end], arr[start])

    # dividing the array into 2 parts and returning respective min & max

    mid = (start + end) // 2

    # calling for left and right min max
    left_min, left_max = recurrMinMax(arr, start, mid)
    right_min, right_max = recurrMinMax(arr, mid + 1, end)
    # returning smaller min and bigger max
    return min(left_min, right_min), max(right_max, left_max)


if __name__ == "__main__":
    arr = [1000, 11, 445, 1, 330, 3000]
    minVal, maxVal = recurrMinMax(arr, 0, len(arr) - 1)
    print(minVal, maxVal)
