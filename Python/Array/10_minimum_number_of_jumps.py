"""
Idea:
iterating through each index, storing the last possible index to jump to .
& counting jumps every time we run out of steps.
-No need to store which index we need to jump from, as we just need count.
"""


def minJumps(arr, n):
    # checking if array has only 0/1 element, to return 0 as we are already in  end position
    if n <= 1:
        return 0
    # checking if element is 0, as we can't reach end element
    if arr[0] == 0:
        return -1

    maxIndexPossible = arr[0]  # highest index element achievable from current index
    stepsAvailable = arr[0]  # stores number of steps that can be taken from current index
    jumps = 1  # no. of jumps taken so far

    for i in range(1, n):
        # if we reached end of array, return no. of jumps
        if i == n - 1:
            return jumps

        # setting var to max index element we can reach from current index
        maxIndexPossible = max(maxIndexPossible, i + arr[i])

        stepsAvailable -= 1  # reducing steps count after each iterated element

        if stepsAvailable == 0:
            # if no more steps can be taken, we need to take a jump
            jumps += 1

            stepsAvailable = maxIndexPossible - i
            # setting up steps as maximum distance allowed to travel

            if i >= maxIndexPossible:  # if we crossed max possible index, returning
                return -1

    return -1  # if we weren't able to reach last index, returning -1


if __name__ == '__main__':
    T = int(input())
    for j in range(T):
        nu = int(input())
        Arr = [int(x) for x in input().split()]
        ans = minJumps(Arr, nu)
        print(ans)
