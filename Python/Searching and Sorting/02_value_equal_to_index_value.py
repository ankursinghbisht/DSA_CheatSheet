"""
Idea:
iterating the array, and returning equal value elements

"""


class Solution:

    def valueEqualToIndex(self, arr, n):
        res = []
        for i in range(n):
            if arr[i] == i + 1:
                res.append(arr[i])
        return res


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.valueEqualToIndex(arr, n)
        if len(ans) == 0:
            print("Not Found")
        else:
            for x in ans:
                print(x, end=" ")
            print()
        tc -= 1

