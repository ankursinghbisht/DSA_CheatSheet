"""
Idea:
Iterating through array, storing sum of temporary subarray using 2 pointers,
& moving them if sum is higher or lower ( using sliding window technique)
"""


def smallestSubWithSum(a, n, x):
    total = 0
    ans = n + 1
    i = j = 0
    while i < n and j < n:

        # moving front & back pointer till we have sum > target
        while total <= x and j < n:
            total += a[j]
            j += 1
        while total > x and i < n:
            # checking if subarray is smaller than current one
            ans = min(ans, j - i)
            total -= a[i]
            i += 1

    return 0 if ans > n else ans


def main():
    T = int(input())

    while T > 0:
        sz = [int(x) for x in input().strip().split()]
        n, m = sz[0], sz[1]
        a = [int(x) for x in input().strip().split()]
        print(smallestSubWithSum(a, n, m))

        T -= 1


if __name__ == "__main__":
    main()
