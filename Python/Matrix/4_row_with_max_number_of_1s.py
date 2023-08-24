"""
Idea:
counting no. of one's in each row, and storing the value of row, which has the highest count.
"""


class Solution:

    def rowWithMax1s(self, arr, n, m):
        ans = -1
        max = 0
        for i in range(n):
            count = 0
            for j in range(m):
                if arr[i][j] == 1:
                    count += 1

            if max < count:
                max = count
                ans = i

        return ans


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))

        inputLine = list(map(int, input().strip().split()))
        arr = [[0 for j in range(m)] for i in range(n)]

        for i in range(n):
            for j in range(m):
                arr[i][j] = inputLine[i * m + j]
        ob = Solution()
        ans = ob.rowWithMax1s(arr, n, m)
        print(ans)
        tc -= 1
