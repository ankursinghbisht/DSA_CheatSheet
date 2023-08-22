"""
Idea:
Iterating through each element of array & calculate Sum of each element
If number is 0 or is seen before, it means there exists a subarray with 0 sum.
"""


def subArrayExists(self, arr, n):
    total = 0
    sumSet = set()
    # using set to find if there are 2 sums equal.
    for i in range(n):
        total += arr[i]
        if total == 0 or sum in sumSet:
            # iterating through each element & finding if sum is seen before
            return True
        sumSet.add(total)
    return False


def main():
    T = int(input())
    while T > 0:

        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        if subArrayExists(arr, n):
            print("Yes")
        else:
            print("No")

        T -= 1


if __name__ == "__main__":
    main()
