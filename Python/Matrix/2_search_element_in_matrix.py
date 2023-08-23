"""
Idea:
Using Binary search in 2D matrix,
- if element is greater than target,decreasing the column
- if element is smaller than target, increasing the row value
"""


class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:

        if len(matrix) == 0 or len(matrix[0]) == 0:
            # checking if arrays is empty or not
            return False

        row = len(matrix) - 1
        col = len(matrix[0]) - 1

        if target == matrix[0][0]:
            # f matrix has only 1 element
            return True

        x = 0
        y = col  # declaring the indices to traverse the matrix

        while x <= row and y >= 0:
            if target == matrix[x][y]:
                return True

            elif target < matrix[x][y]:
                # if element is bigger than target, decreasing the column value
                y -= 1
            else:
                # if element is smaller than target, increasing the row value
                x += 1

        return False


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
