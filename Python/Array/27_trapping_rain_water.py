"""
IDea:
Iterating through each element, and finding max elements in both directions & storing in arrays
Now, total water collected will be water stored at each index.
So, using max values, selecting min & subtracting height of that index to find water there.
"""


def trappingWater(arr, n):
    water = 0
    # setting up arrays to store max in both directions at each index
    left_max = [0] * n
    right_max = [0] * n
    left_max[0] = arr[0]
    right_max[n - 1] = arr[n - 1]

    for i in range(1, n):
        # iterating left to right to find max
        left_max[i] = max(left_max[i - 1], arr[i])

    for i in range(n - 2, -1, -1):
        # iterating right to left to find max
        right_max[i] = max(right_max[i + 1], arr[i])

    for i in range(n):
        # adding water at that index to total
        water += max(0, min(left_max[i], right_max[i]) - arr[i])

    return water


def main():
    T = int(input())
    while T > 0:
        n = int(input())

        arr = [int(x) for x in input().strip().split()]
        print(trappingWater(arr, n))

        T -= 1


if __name__ == "__main__":
    main()

