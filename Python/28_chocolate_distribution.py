"""
Idea:
sorting & finding subarray which has the least difference between first & last element.
"""


def findMinDiff(arr, n, students):
    ans = float('inf')

    arr.sort()
    for i in range(0, n - students):
        # calculating the difference between first & last element of subarray
        temp = arr[i + students - 1] - arr[i]
        ans = min(temp, ans)
    return ans


if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        N = int(input())
        A = [int(x) for x in input().split()]
        M = int(input())
