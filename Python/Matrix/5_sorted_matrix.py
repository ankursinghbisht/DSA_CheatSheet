"""
Idea:
storing matrix in list & sorting and rearranging in the matrix & returning
"""


class Solution:
    def sortedMatrix(self, N, Mat):
        arr = []
        for i in range(N):
            for j in range(N):
                arr.append(Mat[i][j])
        arr.sort()
        k = 0
        for i in range(N):
            for j in range(N):
                Mat[i][j] = arr[k]
                k += 1

        return Mat


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        v = []
        for i in range(N):
            a = list(map(int, input().strip().split()))
            v.append(a)
        ob = Solution()
        ans = ob.sortedMatrix(N, v)
        for i in range(N):
            for j in range(N):
                print(ans[i][j], end=" ")
            print()
