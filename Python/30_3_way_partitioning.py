"""
Idea:
We traverse the given array of elements from left.
We keep track of two pointers, first to store next position of smaller element(smaller than range) from beginning,
and second to store next position of greater element from end.
while traversing the array use these two pointers to place elements according to their range.
"""


def threeWayPartition(array, a, b):
    n = len(array)
    start, end = 0, n - 1
    # Using two pointers which help in finding the index with which
    # the elements need to be swapped if they are not in correct position.

    i = 0
    while i <= end:
        if array[i] < a:
            # If current element is smaller than lower range, we swap
            # it with value on next available smallest position.
            array[i], array[start] = array[start], array[i]
            i += 1
            start += 1
        elif array[i] > b:
            # If current element is greater than higher range, we swap
            # it with value on next available greatest position.
            array[i], array[end] = array[end], array[i]
            end -= 1
        else:
            # else we just move ahead in the array.
            i += 1


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        array = list(map(int, input().strip().split()))
        a, b = list(map(int, input().strip().split()))
        threeWayPartition(array, a, b)
        print(array)
