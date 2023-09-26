"""
Idea:
finding mid-point at each iteration , summing difference between each element & mid found.
If sum is found , return.
"""


def max_sawblade_height(arr, n, m):
    arr.sort()
    low, high, result = 0, arr[-1], 0

    while low <= high:
        mid = low + (high - low) // 2  # assuming the required height is found
        total_cut = 0

        for tree_height in arr:  # summing total height of wood cut
            if tree_height > mid:
                total_cut += tree_height - mid

        if total_cut >= m:  # if cut wood is more than required
            result = mid
            low = mid + 1
        else:
            high = mid - 1

    return result


if __name__ == "__main__":
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    print(max_sawblade_height(A, n, m))
