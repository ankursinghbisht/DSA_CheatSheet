"""
Idea:
dividing the list in 2 parts, generating all subsets and their sum of both halves & appending it to the list
sorting the second half, and using binary search to find the corresponding element that sums within the range.
"""
from bisect import bisect_left, bisect_right


def count_subsets_with_sum_range(N, A, B, S):
    half_N = N // 2
    other_half_N = N - half_N

    subset_sum1 = [0] * (1 << half_N)
    subset_sum2 = [0] * (1 << other_half_N)

    # Generate all possible subsets for the first half of the array
    for mask in range(1 << half_N):
        for i in range(half_N):
            if mask & (1 << i):
                subset_sum1[mask] += S[i]

    # Generate all possible subsets for the second half of the array
    for mask in range(1 << other_half_N):
        for i in range(other_half_N):
            if mask & (1 << i):
                subset_sum2[mask] += S[half_N + i]

    # Sort the second half of the subsets for binary search
    subset_sum2.sort()

    count = 0

    # Count the subsets with sums between A and B
    for i in range(1 << half_N):
        target1 = A - subset_sum1[i]
        target2 = B - subset_sum1[i]

        # Use binary search to find the range of possible sums in the second half
        low = bisect_left(subset_sum2, target1)
        high = bisect_right(subset_sum2, target2)

        count += high - low

    return count


# Input reading
N, A, B = map(int, input().split())
S = [int(input()) for _ in range(N)]

result = count_subsets_with_sum_range(N, A, B, S)
print(result)
