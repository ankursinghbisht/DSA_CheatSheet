"""
Idea:
set max and temp sum variable, set max to temp, if temp>max
& set temp=0 if temp goes below 0
"""


def maxSubArray(arr):
    maxValue = float('-inf')
    tempMax = 0

    for i in range(len(arr)):
        tempMax += arr[i]
        if maxValue < tempMax:
            maxValue = tempMax

        if tempMax < 0:
            tempMax = 0
    return maxValue


if __name__ == "__main__":
    array = [1, 2, 3, -2, 5]
    print(maxSubArray(array))
    print()
