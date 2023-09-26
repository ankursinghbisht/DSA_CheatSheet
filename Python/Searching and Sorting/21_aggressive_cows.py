"""
Idea:
sorting the array, and using binary search to solve
-at each iteration of calculating 'mid' of the array,
 checking if all cows can be placed in the array at distance calculated by 'mid'
"""


def can_place_cows(stalls, n, c, min_dist):
    cows_placed = 1
    last_position = stalls[0]

    for i in range(1, n):
        # putting each cow in position with distance between them as 'minDist'
        if stalls[i] - last_position >= min_dist:
            cows_placed += 1
            last_position = stalls[i]

        if cows_placed == c:
            return True

    return False


def largest_min_distance(stalls, n, c):
    stalls.sort()

    low = 1  # Minimum possible distance
    high = stalls[n - 1] - stalls[0]  # Maximum possible distance
    result = -1

    while low <= high:
        mid = low + (high - low) // 2

        if can_place_cows(stalls, n, c, mid): # checking if all cows can be placed in positions given
            result = mid
            low = mid + 1
        else:
            high = mid - 1

    return result


t = int(input())
for _ in range(t):
    n, c = map(int, input().split())
    stall_positions = [int(input()) for _ in range(n)]

    result = largest_min_distance(stall_positions, n, c)
    print(result)
