"""
Idea:
start comparing from the leftmost element and find the difference between the current array element and x.
Let this difference be ‘diff’.
From the given property of the array, we always know that x must be at least ‘diff/k’ away,
so instead of searching one by one, we jump ‘diff/k’.
"""


def search(arr, n, x, k):
    i = 0
    while i < n:
        if arr[i] == x:
            return i
        i += max(1, abs(arr[i] - x) // k)  # jumping diff/k instead of 1, if it's greater

    return -1


for _ in range(0, int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().strip().split()))
    x = int(input())
    ans = search(arr, n, x, k)
    print(ans)
