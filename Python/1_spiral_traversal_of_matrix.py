"""
Idea:
-Breaking problem into smaller parts.
-Iterating the matrix from outermost ring, then inner ring & appending the answer at each iteration.
"""


class Solution:

    def spirallyTraverse(self, matrix, r, c):
        ans = []
        row_start, row_end = 0, r - 1
        col_start, col_end = 0, c - 1

        while row_start <= row_end and col_start <= col_end:
            # Traverse top row
            for i in range(col_start, col_end + 1):
                ans.append(matrix[row_start][i])
            row_start += 1

            # Traverse right column
            for i in range(row_start, row_end + 1):
                ans.append(matrix[i][col_end])
            col_end -= 1

            # Traverse bottom row
            if row_start <= row_end:
                for i in range(col_end, col_start - 1, -1):
                    ans.append(matrix[row_end][i])
                row_end -= 1

            # Traverse left column
            if col_start <= col_end:
                for i in range(row_end, row_start - 1, -1):
                    ans.append(matrix[i][col_start])
                col_start += 1

        return ans


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        r, c = map(int, input().strip().split())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix = []
        for i in range(r):
            row = []
            for j in range(c):
                row.append(values[k])
                k += 1
            matrix.append(row)
        obj = Solution()
        ans = obj.spirallyTraverse(matrix, r, c)
        for i in ans:
            print(i, end=" ")
        print()
