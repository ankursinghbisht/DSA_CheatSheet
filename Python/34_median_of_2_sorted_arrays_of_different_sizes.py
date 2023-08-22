"""
Idea:
If arrays are merged, then finding the indices which include the median (M+N+1)/2
, partitioning the array (finding the elements which will be in left part of merged array).
-Checking if partitioning is done correct, returning the median
( keeping in mind the length of combined arrays)-else, shifting the mid-pointers.
"""


def MedianOfArrays(A, B):
    n = len(A)
    m = len(B)

    if n > m:
        return MedianOfArrays(B, A)  # Swapping to make A smaller

    start = 0
    end = n
    realmidinmergedarray = (n + m + 1) // 2

    while start <= end:
        mid = (start + end) // 2
        leftAsize = mid
        leftBsize = realmidinmergedarray - mid

        # declaring & checking overflow of indices
        leftA = A[leftAsize - 1] if leftAsize > 0 else float("-inf")
        leftB = B[leftBsize - 1] if leftBsize > 0 else float("-inf")
        rightA = A[leftAsize] if leftAsize < n else float("inf")
        rightB = B[leftBsize] if leftBsize < m else float("inf")

        # if correct partition is done
        if leftA <= rightB and leftB <= rightA:
            if (m + n) % 2 == 0:
                return (max(leftA, leftB) + min(rightA, rightB)) / 2
            return max(leftA, leftB)
        elif leftA > rightB:
            end = mid - 1
        else:
            start = mid + 1

    return 0


if __name__ == '__main__':
    tcs = int(input())

    for _ in range(tcs):
        m = input()
        arr1 = [int(x) for x in input().split()]
        n = input()
        arr2 = [int(x) for x in input().split()]

        print(MedianOfArrays(arr1, arr2))
