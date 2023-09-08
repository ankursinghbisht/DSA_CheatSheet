"""
Idea:
use recursion to traverse through each character of the matrix and taking each character as a start of the string to be found.
if found, repeating for all directions
"""


class Solution:
    def internalSearch(self, target, row, col, mat, row_max, col_max, index):
        found = 0
        if 0 <= row <= row_max and 0 <= col <= col_max and target[index] == mat[row][col]:
            # If characters are matched
            match = target[index]
            index += 1

            mat[row][col] = 0

            if target[index] == 0:
                found = 1  # If the string has ended
            else:
                # Through backtracking, search in every direction
                found += self.internalSearch(target, row, col + 1, mat, row_max, col_max, index)
                found += self.internalSearch(target, row, col - 1, mat, row_max, col_max, index)
                found += self.internalSearch(target, row + 1, col, mat, row_max, col_max, index)
                found += self.internalSearch(target, row - 1, col, mat, row_max, col_max, index)
            mat[row][col] = match
        return found

    def findOccurrence(self, mat, target):
        found = 0
        row_count = len(mat)
        col_count = len(mat[0])

        for r in range(row_count):
            for c in range(col_count):
                found += self.internalSearch(target, r, c, mat, row_count - 1, col_count - 1, 0)
        return found


# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        line = input().strip().split()
        R = int(line[0])
        C = int(line[1])
        mat = []
        for _ in range(R):
            mat.append([x for x in input().strip().split()])
        target = input()
        obj = Solution()
        print(obj.findOccurrence(mat, target))
# } Driver Code Ends
