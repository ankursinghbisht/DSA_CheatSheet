"""
Idea:
calculating product from first to last at each element & storing max value
,performing above step in both direction.
"""


def maxProduct(arr):
    ans = float('-inf')
    temp = 1

    # Traverse the array from left to right
    for num in arr:
        temp *= num  # Accumulate the product
        if ans < temp:
            ans = temp  # Update the maximum product if needed
        if temp == 0:
            temp = 1  # Reset temp if encountered zero

    temp = 1  # Reset temp

    # Traverse the array from right to left
    for num in reversed(arr):
        temp *= num  # Accumulate the product
        if ans < temp:
            ans = temp  # Update the maximum product if needed
        if temp == 0:
            temp = 1  # Reset temp if encountered zero

    return ans


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        array = list(map(int, input().strip().split()))
        result = maxProduct(array)
        print(result)
        tc -= 1
