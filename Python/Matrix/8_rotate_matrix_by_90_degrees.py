
"""
00 01 02                20 10 00
10 11 12       ---->>   21 11 01
20 21 22                22 12 02

Idea:
In any row, for every decreasing row index i,
there exists a constant column index j, such that j = current_row_index.
"""


N = 4


def rotate90Clockwise(arr):
    global N
    # printing the matrix on the basis of
    # observations made on indices.
    for j in range(N):
        for i in range(N - 1, -1, -1):
            print(arr[i][j], end=" ")
        print()


arr = [[1, 2, 3, 4],
       [5, 6, 7, 8],
       [9, 10, 11, 12],
       [13, 14, 15, 16]]
rotate90Clockwise(arr)

