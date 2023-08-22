"""
Idea: (using sliding windows technique)
Calculating total variables smaller than k, to get window length.
starting from index 0, calculate how many elements are greater than k in particular windows
-slide window at each iteration & checking if unwanted elements are least, (that will be the answer)
"""


def minSwap(arr, n, k):
    count = 0  # total elements smaller than k
    for i in range(n):
        if arr[i] <= k:
            count += 1

    bad = 0  # it stores total numbers greater than k
    for i in range(count):
        if arr[i] > k:
            bad += 1

    i = count
    j = 0

    ans = bad

    while i < n:
        # iterating in array using 2 pointers, if pointer pointing behind has value greater than k,
        # decrease the 'bad' variable, as total unwanted elements will decrease by 1, if we shift window
        if arr[j] > k:
            bad -= 1
        # increasing 'bad' variable if pointer ahead has greater value than k,
        # as total unwanted elements will increase if we shift the windows
        if arr[i] > k:
            bad += 1
        i += 1
        j += 1

        ans = min(ans, bad)
    return ans


for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    k = int(input())
    ans = minSwap(arr, n, k)
    print(ans)
