"""
Idea:
The idea is to increase the first i towers by k and decrease the rest tower by k after sorting the heights,
then calculate the maximum height difference.

Steps:
-sort the array
-Try to make each height of the tower maximum by decreasing the height of all the towers to the right by k
and increasing all the height of the towers to the left by k.
Check whether the current index tower has the maximum height or not by comparing it with a[n]-k.
If the tower’s height is greater than the a[n]-k then it’s the tallest tower available.
-find the shortest tower and minimize the difference between these two towers.
"""


def getMinDiff(arr, n, k):
    arr.sort()

    minVal = arr[0]
    maxVal = arr[n - 1]
    result = maxVal - minVal
    # setting up minimum difference & current min and max values of towers.

    for i in range(1, n):
        # iterating through each element, and checking if value is potisive or not
        if arr[i] - k < 0:
            continue

        # replacing min value with first element of array as reference & same with max value
        minVal = min(arr[0] + k, arr[i] - k)
        maxVal = max(arr[n - 1] - k, arr[i - 1] + k)

        result = min(result, maxVal - minVal)
    return result


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        number = int(input())
        length = int(input())
        array = list(map(int, input().strip().split()))
        ans = getMinDiff(array, length, number)
        print(ans)
        tc -= 1
