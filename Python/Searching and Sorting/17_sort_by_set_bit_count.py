"""
Idea:
sorting the array using lambda function
bin(x) converts string to its binary form ( 5 -> '0b101'
bin(x)[2:0]-removing 1st 2 chars ('0b')
count('1')- counts no. of 1 in string
"""


class Solution:
    # Function to sort the array by the count of set bits in each element
    def sortBySetBitCount(self, arr, n):
        # Sorting the array based on the count of set bits in each element
        arr.sort(key=lambda x: -bin(x)[2:].count('1'))


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        ob.sortBySetBitCount(arr, n)
        print(*arr)

        T -= 1


if __name__ == "__main__":
    main()
