"""
Idea:
Preprocessing the matrix such that index(i, j) stores max of elements in matrix from (i, j) to (N-1, N-1)
and finding max value by subtracting the max value from that current index to max value matrix.
"""


class Solution:
    def findMaxValue(self,Mat):
        N = len(Mat)
        MaxArr = [[0] * N for _ in range(N)]
        ans = float("-inf")

        MaxArr[N - 1][N - 1] = Mat[N - 1][N - 1]
        MaxValue = MaxArr[N - 1][N - 1]

        # Preprocess last row
        for i in range(N - 2, -1, -1):
            if MaxValue < Mat[N - 1][i]:
                MaxValue = Mat[N - 1][i]
            MaxArr[N - 1][i] = MaxValue

        MaxValue = MaxArr[N - 1][N - 1]

        # Preprocess last column
        for i in range(N - 2, -1, -1):
            if MaxValue < Mat[i][N - 1]:
                MaxValue = Mat[i][N - 1]
            MaxArr[i][N - 1] = MaxValue

        # Preprocess rest of the Matrix from bottom
        for i in range(N - 2, -1, -1):
            for j in range(N - 2, -1, -1):
                ans = max(ans, MaxArr[i + 1][j + 1] - Mat[i][j])
                MaxArr[i][j] = max(Mat[i][j], max(MaxArr[i][j + 1], MaxArr[i + 1][j]))

        return ans


if __name__ == '__main__':
    mat = [
        [1, 2, -1, -4, -20],
        [-8, -3, 4, 2, 1],
        [3, 8, 6, 1, 3],
        [-4, -1, 1, 7, -6],
        [0, -4, 10, -5, 1]
    ]
    ob=Solution()
    print("Maximum Value is", ob.findMaxValue(mat))

